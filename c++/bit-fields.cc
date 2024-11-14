#include <stdint.h>
#include <iostream>


#define PT_MPEG_TS  33


struct Rtp_header {
    uint8_t version         : 2;
    uint8_t padding         : 1;
    uint8_t extension       : 1;
    uint8_t csrc_count      : 4;
    uint8_t marker          : 1;
    uint8_t payload_type    : 7;
    uint16_t sequence_number;
    uint32_t timestamp;
    uint32_t ssrc;

    Rtp_header();
};


Rtp_header::Rtp_header()
    : version(2),
      padding(0),
      extension(0),
      csrc_count(0),
      marker(0),
      payload_type(PT_MPEG_TS),
      sequence_number(1234),
      timestamp(111111),
      ssrc(333333)
{
}


int main()
{
    Rtp_header rh;

    std::cout << "sizeof(Rtp_header): " << sizeof(Rtp_header) << std::endl
              << std::endl
              << "version:         " << int(rh.version)      << std::endl
              << "padding:         " << int(rh.padding)      << std::endl
              << "extension:       " << int(rh.extension)    << std::endl
              << "csrc_count:      " << int(rh.csrc_count)   << std::endl
              << "marker:          " << int(rh.marker)       << std::endl
              << "payload_type:    " << int(rh.payload_type) << std::endl
              << "sequence_number: " << rh.sequence_number   << std::endl
              << "timestamp:       " << rh.timestamp         << std::endl
              << "ssrc:            " << rh.ssrc              << std::endl;

    return 0;
}
