#include <unistd.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

extern "C" {

#include <libavutil/dict.h>
#include <libavformat/avformat.h>
#include <libavutil/error.h>

}


static std::string error_to_str(int rc);


int main()
{
    std::string ipaddr("127.0.0.1");
    int port = 16010;
    std::string mediatype("audio");

    std::string ifsdp("/tmp/input.sdp");
    std::ofstream sdp(ifsdp);
    if (!sdp) {
        std::cerr << "failed to open file: " << ifsdp << std::endl;
        return 1;
    }

    // SDP:
    // v=0
    // o=- 0 0 IN IP4 127.0.0.1
    // s=No Name
    // c=IN IP4 127.0.0.1
    // t=0 0
    // a=tool:libavformat 54.20.3
    // m=audio 6060 RTP/AVP 97
    // b=AS:27
    // a=rtpmap:97 speex/16000

    sdp << "v=0\r\n"
        << "o=- 0 0 IN IP4 " << ipaddr << "\r\n"
        << "s=No Name\r\n"
        << "c=IN IP4 " << ipaddr << "\r\n"
        << "t=0 0\r\n"
        << "a=tool:libavformat 54.20.3\r\n"
        << "m=" << mediatype << " " << port << " RTP/AVP 97\r\n"
        << "b=AS:27\r\n"
        << "a=rtpmap:97 speex/16000\r\n";
    sdp.close();

    avcodec_register_all();
    // av_log_set_callback(avlog_callback);
    //av_log_set_level(AV_LOG_DEBUG);
    av_register_all();
    int rc = avformat_network_init();
    if (rc < 0) {
        std::cerr << "avformat_network_init failed: " << error_to_str(rc);
        return 1;
    }

    AVInputFormat *ifmt = av_find_input_format("sdp");
    // AVInputFormat *ifmt = av_find_input_format("rtp");
    if (!ifmt) {
        std::cerr << "can't find input format" << std::endl;
        return 1;
    }

    AVFormatContext *ic = 0;
    // Dictionary dict;
    // av_dict_set(&dict.ptr, "rtp_transport", "udp", 0);
    // rc = avformat_open_input(&ic, url.c_str(), ifmt, 0);//&dict.ptr);
    rc = avformat_open_input(&ic, ifsdp.c_str(), ifmt, 0);//&dict.ptr);
    if (rc != 0) {
        std::cerr << "avformat_open_input failed: " << error_to_str(rc) << std::endl;
        return 1;
    }

    std::cout << "input opened, sleeping..." << std::endl;
    sleep(1);


    AVFormatContext *oc = avformat_alloc_context();
    if (!oc) {
        std::cerr << "error allocating avio context" << std::endl;
        return 1;
    }
    oc->oformat = av_guess_format("rtp", ifsdp.c_str(), 0);
    // oc->oformat = av_guess_format("rtp", 0, 0);
    if (!oc->oformat) {
        std::cerr << "could not find suitable output format" << std::endl;
        return 1;
    }
    // oc->oformat->video_codec = AV_CODEC_ID_H264;
    // oc->oformat->audio_codec = AV_CODEC_ID_SPEEX;

    std::ostringstream os;
    os << "rtp://127.0.0.1:" << port;
    std::string outputurl = os.str();
    std::cout << "outputurl: " << outputurl << std::endl;
    snprintf(oc->filename, sizeof(oc->filename), "%s", outputurl.c_str());

    // videoencoder.setup_stream(oc.get(), bwparams);
    // audioencoder.setup_stream(oc.get(), bwparams);

    av_dump_format(oc, 0, outputurl.c_str(), 1);

    // write the stream header
    AVDictionary *dict = 0;
    av_dict_set(&dict, "rtpflags", "parse_rtcp", 0);
    rc = avformat_write_header(oc, &dict);
    if (rc < 0) {
        std::cerr << "error writing stream header: " << error_to_str(rc) << std::endl;
        return 1;
    }


    return 0;
}


std::string error_to_str(int rc)
{
    char buf[512];
    av_strerror(rc, buf, sizeof(buf));

    return std::string(buf);
}
