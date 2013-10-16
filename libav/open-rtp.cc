#include <unistd.h>
#include <iostream>
#include <sstream>
#include <string>

extern "C" {

#include <libavutil/dict.h>
#include <libavformat/avformat.h>
#include <libavutil/error.h>

}


static std::string error_to_str(int rc);


int main()
{
    avcodec_register_all();

    // av_log_set_callback(avlog_callback);
    av_log_set_level(AV_LOG_DEBUG);

    av_register_all();
    int rc = avformat_network_init();
    if (rc < 0) {
        std::cerr << "avformat_network_init failed: " << error_to_str(rc);
        return 1;
    }

    AVInputFormat *ifmt = av_find_input_format("rtsp");
    if (!ifmt) {
        std::cerr << "can't find input format" << std::endl;
        return 1;
    }

    int port = 6000;
    std::ostringstream os;
    os << "rtp://127.0.0.1:" << port << "?connect=0";
    std::string url = os.str();
    std::cout << "url: " << url << std::endl;

    AVFormatContext *ic = 0;
    // Dictionary dict;
    // av_dict_set(&dict.ptr, "rtp_transport", "udp", 0);
    rc = avformat_open_input(&ic, url.c_str(), ifmt, 0);//&dict.ptr);
    if (rc != 0) {
        std::cerr << "avformat_open_input failed: " << error_to_str(rc) << std::endl;
        return 1;
    }

    sleep(5);

    return 0;
}


std::string error_to_str(int rc)
{
    char buf[512];
    av_strerror(rc, buf, sizeof(buf));

    return std::string(buf);
}
