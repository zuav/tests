#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <iomanip>
#include <chrono>


#define SEND_PACKETS_0(Send_class_name, TTL, var)                       \
    {                                                                   \
        Send_class_name snd;                                            \
        auto start = std::chrono::high_resolution_clock::now();         \
        for (int i=0; i<num; ++i) {                                     \
            Packet pkt(i);                                              \
            snd.send(&pkt);                                             \
        }                                                               \
        auto end = std::chrono::high_resolution_clock::now();           \
        std::chrono::nanoseconds diff = end - start;                    \
        std::cout << std::setw(17) << TTL << diff.count() << ", " << 0  \
                  << std::endl;                                         \
        var = diff.count();                                             \
    }


#define SEND_PACKETS_1(Send_class_name, TTL)                            \
    {                                                                   \
        Send_class_name snd;                                            \
        auto start = std::chrono::high_resolution_clock::now();         \
        for (int i=0; i<num; ++i) {                                     \
            Packet pkt(i);                                              \
            snd.send(&pkt);                                             \
        }                                                               \
        auto end = std::chrono::high_resolution_clock::now();           \
        std::chrono::nanoseconds diff = end - start;                    \
        std::cout << std::setw(17) << TTL << diff.count() << ", "       \
                  << double(diff.count() - count0)/num                  \
                  << std::endl;                                         \
    }



static int open_socket();

// (/ 1316 4) 329
// (* 329 4)  1316
struct Packet {
    static constexpr int size = 329;
    int buf[size];

    Packet(int);
};


class Send_rtp_base {
public:
    Send_rtp_base();

    virtual void send(const Packet *);

protected:
    void make_addr(sockaddr_in&, uint16_t port);
    void update_fec_packet(Packet *, const Packet *);
    void send_packet(const Packet *, const char *type, const sockaddr_in *);

    int sock;
    const int port;

private:
    sockaddr_in addr;
};


class Send_rtp_no_fec : public Send_rtp_base {
public:
    Send_rtp_no_fec() = default;
};


class Send_rtp_fec_single : public Send_rtp_base {
public:
    Send_rtp_fec_single();

    void send(const Packet *) override;

private:
    const int port2;
    sockaddr_in addr2;
    int ind2;
    int l;
    Packet feclpkt;
};


class Send_rtp_fec_double : public Send_rtp_fec_single {
public:
    Send_rtp_fec_double();

    void send(const Packet *) override;

private:
    const int port4;
    sockaddr_in addr4;
    int ind4;
    int d;
    Packet fecdpkt;
};


class Send_rtp_full : public Send_rtp_base {
public:
    Send_rtp_full(bool fecl, bool fecd);

    void send(const Packet *) override;

private:
    bool fecl;
    const int port2;
    sockaddr_in addr2;
    int ind2;
    int l;
    Packet feclpkt;

    bool fecd;
    const int port4;
    sockaddr_in addr4;
    int ind4;
    int d;
    Packet fecdpkt;
};


class Send_rtp_full_no_fec : public Send_rtp_full {
public:
    Send_rtp_full_no_fec() : Send_rtp_full(false, false) {}
};


class Send_rtp_full_fec_single : public Send_rtp_full {
public:
    Send_rtp_full_fec_single() : Send_rtp_full(true, false) {}
};


class Send_rtp_full_fec_double : public Send_rtp_full {
public:
    Send_rtp_full_fec_double() : Send_rtp_full(true, true) {}
};



int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " number" << std::endl;
        return 1;
    }

    int num = strtol(argv[1], 0, 0);
    std::cout << "number: " << num << std::endl;

    int64_t count0 = 0;

    SEND_PACKETS_0(Send_rtp_no_fec,          "no fec vf:", count0);
    SEND_PACKETS_1(Send_rtp_fec_single,      "single fec vf:");
    SEND_PACKETS_1(Send_rtp_fec_double,      "double fec vf:");
    SEND_PACKETS_1(Send_rtp_full_no_fec,     "no fec if:");
    SEND_PACKETS_1(Send_rtp_full_fec_single, "single fec if:");
    SEND_PACKETS_1(Send_rtp_full_fec_double, "double fec if:");

    return 0;
}


Packet::Packet(int n)
{
    for (int i=0; i<size; ++i)
        buf[i] = n;
}


Send_rtp_base::Send_rtp_base()
    : port(7000),
      sock(socket(PF_INET, SOCK_DGRAM, 0))
{
    if (sock == -1) {
        std::cerr << "error: failed to create socket: " << errno << ": " << strerror(errno) << std::endl;
        exit(2);
    }

    make_addr(addr, port);
}


void Send_rtp_base::send(const Packet *p)
{
    send_packet(p, "DATA", &addr);
}


void Send_rtp_base::make_addr(sockaddr_in& addr, uint16_t port)
{
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
}


void Send_rtp_base::update_fec_packet(Packet *pf, const Packet *pp)
{
    for (int i=0; i<Packet::size; ++i)
        pf->buf[i] ^= pp->buf[i];
}


void Send_rtp_base::send_packet(const Packet *p, const char *type, const sockaddr_in *paddr)
{
    int rc = sendto(sock, p->buf, sizeof(p->buf), 0, reinterpret_cast<const sockaddr *>(paddr), sizeof(sockaddr_in));
    if (rc == -1) {
        std::cerr << "error: failed to send " << type << " packet: " << errno << ": " << strerror(errno) << std::endl;
        exit(3);
    }
}


Send_rtp_fec_single::Send_rtp_fec_single()
    : port2(port + 2),
      ind2(0),
      l(4),
      feclpkt(0)
{
    make_addr(addr2, port2);
}


void Send_rtp_fec_single::send(const Packet *p)
{
    Send_rtp_base::send(p);

    update_fec_packet(&feclpkt, p);

    if (ind2++ >= l) {
        ind2 = 0;
        send_packet(p, "FEC_L", &addr2);
        feclpkt = Packet(0);
    }
}


Send_rtp_fec_double::Send_rtp_fec_double()
    : port4(port + 4),
      ind4(0),
      d(5),
      fecdpkt(0)
{
    make_addr(addr4, port4);
}


void Send_rtp_fec_double::send(const Packet *p)
{
    Send_rtp_fec_single::send(p);

    update_fec_packet(&fecdpkt, p);

    if (ind4++ >= d) {
        ind4 = 0;
        send_packet(p, "FEC_D", &addr4);
        fecdpkt = Packet(0);
    }
}


Send_rtp_full::Send_rtp_full(bool fl, bool fd)
    : fecl(fl),
      port2(port + 2),
      ind2(0),
      l(4),
      feclpkt(0),
      fecd(fd),
      port4(port + 4),
      ind4(0),
      d(5),
      fecdpkt(0)
{
    if (fecl)
        make_addr(addr2, port2);

    if (fecd)
        make_addr(addr4, port4);
}


void Send_rtp_full::send(const Packet *p)
{
    Send_rtp_base::send(p);

    if (fecl) {
        update_fec_packet(&feclpkt, p);
        if (ind2++ >= l) {
            ind2 = 0;
            send_packet(p, "FEC_L", &addr2);
            feclpkt = Packet(0);
        }
    }

    if (fecd) {
        update_fec_packet(&fecdpkt, p);
        if (ind4++ >= l) {
            ind4 = 0;
            send_packet(p, "FEC_D", &addr4);
            fecdpkt = Packet(0);
        }
    }
}
