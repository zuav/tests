#include <errno.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <variant>
#include <chrono>


enum Protocol { SRT, UDP };


struct Srt_data {
    int         group;
    int         mode;
    std::string passphrase;
    int32_t     fc;
    int32_t     buf_size;
    int32_t     pb_key_len;
    int32_t     peer_latency;
    int32_t     recv_latency;
    std::string stream_id;
    int64_t     max_bw;
    int32_t     ip_ttl;
    int32_t     ip_tos;

    Srt_data();
    ~Srt_data() = default;
};


struct Udp_data {
    int32_t ip_tos;

    Udp_data();
};


struct Data_union {
    int protocol;
    union {
        Udp_data udp;
        Srt_data srt;
    };

    ~Data_union();
};


struct Data_variant {
    int protocol;
    std::variant<Srt_data, Udp_data> protocol_data;

    Data_variant();

    const Srt_data& srt_data() const { return std::get<Srt_data>(protocol_data); }
    const Udp_data& udp_data() const { return std::get<Udp_data>(protocol_data); }
};


static int use_union(int num);
static int use_variant(int num);
static void fill_srt_data(Srt_data& d, int num);
static void fill_udp_data(Udp_data& d, int num);
static int sum_data(const Srt_data&);
static int sum_data(const Udp_data&);


int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << program_invocation_short_name << " num" << std::endl;
        return 1;
    }

    int num = strtol(argv[1], 0, 0);

    auto start0 = std::chrono::high_resolution_clock::now();
    int r0 = 0;
    for (int i=0; i<num; ++i)
        r0 += use_union(i);
    auto end0 = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff0 = end0 - start0;
    std::cout << "union:   " << diff0.count() << " ns, "
              << 0 << ", "
              << r0 << std::endl;

    auto start1 = std::chrono::high_resolution_clock::now();
    int r1 = 0;
    for (int i=0; i<num; ++i)
        r1 += use_variant(i);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::nanoseconds diff1 = end1 - start1;
    std::cout << "variant: " << diff1.count() << " ns, "
              << double(diff1.count() - diff0.count())/num <<  ", "
              << r1 << std::endl;

    return 0;
}


Srt_data::Srt_data()
    : group(0),
      mode(0),
      fc(0),
      buf_size(0),
      pb_key_len(0),
      peer_latency(0),
      recv_latency(0),
      max_bw(0),
      ip_ttl(0),
      ip_tos(0)
{
}


Udp_data::Udp_data()
    : ip_tos(0)
{
}


Data_union::~Data_union()
{
    if (protocol == SRT)
        srt.~Srt_data();
}


Data_variant::Data_variant()
    : protocol(SRT)
{
}


int use_union(int num)
{
    int sum = 0;

    if (num % 2) {
        Udp_data ud;
        Srt_data sd;
        fill_srt_data(sd, num);
        Data_union d { UDP, ud };
        d.protocol = SRT;
        d.srt = sd;
        sum = sum_data(d.srt);
    } else {
        Udp_data ud;
        fill_udp_data(ud, num);
        Data_union d { UDP, ud };
        sum = sum_data(d.udp);
    }

    return sum;
}


int use_variant(int num)
{
    Data_variant d;

    if (num % 2) {
        d.protocol = SRT;
        Srt_data sd;
        fill_srt_data(sd, num);
        d.protocol_data = sd;
    } else {
        d.protocol = UDP;
        Udp_data ud;
        fill_udp_data(ud, num);
        d.protocol_data = ud;
    }

    return (d.protocol == SRT) ? sum_data(d.srt_data()) : sum_data(d.udp_data());
}


void fill_srt_data(Srt_data& d, int num)
{
    d.group        = num;
    d.mode         = num;
    d.passphrase   = std::to_string(num);
    d.fc           = num;
    d.buf_size     = num;
    d.pb_key_len   = num;
    d.peer_latency = num;
    d.recv_latency = num;
    d.stream_id    = std::to_string(num);
    d.max_bw       = num;
    d.ip_ttl       = num;
    d.ip_tos       = num;
}


void fill_udp_data(Udp_data& d, int num)
{
    d.ip_tos = num;
}


int sum_data(const Srt_data& s)
{
    return
        s.group             +
        s.mode              +
        s.passphrase.size() +
        s.fc                +
        s.buf_size          +
        s.pb_key_len        +
        s.peer_latency      +
        s.recv_latency      +
        s.stream_id.size()  +
        s.max_bw            +
        s.ip_ttl            +
        s.ip_tos;
}


int sum_data(const Udp_data& d)
{
    return d.ip_tos;
}
