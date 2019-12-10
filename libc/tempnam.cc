#include <stdio.h>
#include <stdlib.h>
#include <iostream>


int main()
{
    char *ptmp = tempnam("./", "cdr");
    std::cout  << ptmp << std::endl;
    free(ptmp);

    char templ[] = "./cdrXXXXXX";
    int h = mkstemp(templ);
    std::cout  << templ << std::endl;


    return 0;
}
