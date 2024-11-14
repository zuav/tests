#include <iostream>
#include <string>


const std::string RTP_STREAM_STR = R"(
  {
    "active": true,
    "protocol": "RTP",
    "id": "acd6b502-f1a3-4fd8-b251-822bbcf8cdaa",
    "dummy_key": "dummy_value",
    "link": [
      {
        "host": "127.0.0.1",
        "id": "b2bab5fd-125b-4a81-97cc-6cec42f6a18a",
        "port": 4322
      }
    ]
  }
)";


const std::string RTP_PASSTHROUGH_STR = "\"rtp_passthrough\": true,";
const std::string SRT_RTP_HEADER_STR  = "\"srt_rtp_header\": true,";


std::string replace_dummy(const std::string& s, const std::string& keyval)
{
    std::string ss = s;

    auto spos = ss.find("\"dummy_key\"");
    auto epos = ss.find("\n", spos);
    ss.replace(ss.begin() + spos, ss.begin() + epos, keyval);

    return ss;
}



int main()
{
    std::string s = replace_dummy(RTP_STREAM_STR, RTP_PASSTHROUGH_STR);

    std::cout << s << std::endl;

    return 0;
}
