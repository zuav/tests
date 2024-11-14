#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <iomanip>
#include <iostream>


#define RTP_BUF_SIZE 2000


#pragma pack(1)
struct Rtp_header {
    uint8_t csrc_count      : 4;
    uint8_t extension       : 1;
    uint8_t padding         : 1;
    uint8_t version         : 2;
    //
    uint8_t payload_type    : 7;
    uint8_t marker          : 1;
    //
    uint16_t sequence_number;
    uint32_t timestamp;
    uint32_t ssrc;

    Rtp_header();
};
#pragma pack()

Rtp_header::Rtp_header()
    : version(0),
      padding(0),
      extension(0),
      csrc_count(0),
      marker(0),
      payload_type(0),
      sequence_number(0),
      timestamp(0),
      ssrc(0)
{
}


int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << program_invocation_short_name << " port num-packets" << std::endl;
        return 1;
    }

    uint16_t port = std::stoi(argv[1]);
    int numpkts = std::stoi(argv[2]);

    int sock = socket(PF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        std::cerr << "error: failed to create socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }

    sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (sockaddr *) &name, sizeof (name)) < 0) {
        std::cerr << "error: failed to bind socket for port " << port << ": " << strerror(errno) << ": " << errno << std::endl;
        exit(1);
    }


    std::cout << std::left
              << std::setw(13) << "payload_size"
              << std::setw(8)  << "version"
              << std::setw(8)  << "padding"
              << std::setw(10) << "extension"
              << std::setw(11) << "csrc_count"
              << std::setw(7)  << "marker"
              << std::setw(13) << "payload_type"
              << std::setw(16) << "sequence_number"
              << std::setw(11) << "timestamp"
              << std::setw(11) << "ssrc"
              << std::endl;

        for (int i=0; i<numpkts; ++i) {
        char buf[RTP_BUF_SIZE];
        memset(buf, 0, sizeof(buf));
        int rc = recv(sock, buf, sizeof(buf), 0);
        if (rc == -1) {
            std::cerr << "recv failed: " << errno << ": " << strerror(errno) << std::endl;
            continue;
        }

        // uint16_t v = ntohl(*reinterpret_cast<uint16_t *>(buf));
        // *reinterpret_cast<uint16_t*>(buf) = v;

        const Rtp_header *ph = reinterpret_cast<Rtp_header *>(buf);
        std::cout << std::left
                  << std::setw(13) << (rc - sizeof(Rtp_header)) // - (ph->csrc_count * 4))
                  << std::setw(8)  << int(ph->version)
                  << std::setw(8)  << int(ph->padding)
                  << std::setw(10) << int(ph->extension)
                  << std::setw(11) << int(ph->csrc_count)
                  << std::setw(7)  << int(ph->marker)
                  << std::setw(13) << int(ph->payload_type)
                  << std::setw(16) << ntohs(ph->sequence_number)
                  << std::setw(11) << ntohl(ph->timestamp)
                  << std::setw(11) << ntohl(ph->ssrc)
                  << std::endl;
    }

    return 0;
}
