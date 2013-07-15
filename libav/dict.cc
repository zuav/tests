extern "C" {

#include <libavutil/dict.h>

}

#include <iostream>
#include <memory>


struct Free_avdict {
    void operator()(AVDictionary *p) const
        {
            if (p) {
                std::cout << "freeing p: " << std::hex << p << std::endl;
                av_dict_free(&p);
            }
        }
};


int main()
{

    AVDictionary *dict = 0;
    std::shared_ptr<AVDictionary> dictptr(dict, Free_avdict());

    av_dict_set(&dict, "analyzeduration", "0", 0);
    av_dict_set(&dict, "flv_metadata",    "1", 0);
    av_dict_set(&dict, "rtmp_buffer",     "0", 0);
    av_dict_set(&dict, "rtmp_live",    "live", 0);
    dictptr.reset(dict);

    return 0;
}
