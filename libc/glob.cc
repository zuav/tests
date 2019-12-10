#include <glob.h>
#include <unistd.h>
#include <string>
#include <iostream>


int main()
{
    std::string cwd = getcwd(0, 0);
    std::string mask = cwd + "/*.rtt";
    glob_t gvec;

    std::cout << "mask: " << mask << std::endl;

    switch (int rc = glob(mask.c_str(), 0, 0, &gvec)) {
    case 0:
        break;
    case GLOB_ABORTED:
        std::cerr << "glob failed with rc: GLOB_ABORTED\n";
        break;
    case GLOB_NOMATCH:
        std::cout << "no files found match the mask\n";
        break;
    default:
        std::cerr << "glob failed with unexpected rc: " << rc << "\n";
        break;
    }

    std::cout << "found files: " << gvec.gl_pathc << std::endl
              << "gvec.gl_pathv: " << static_cast<void*>(gvec.gl_pathv) << std::endl;

    for (int i=0; i<gvec.gl_pathc; i++)
        std::cout << gvec.gl_pathv[i] << std::endl;


    return 0;
}
