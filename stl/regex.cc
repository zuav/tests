#include <regex>
#include <iostream>

int main(int, char *[])
{
    // std::string rs = "^[0-9]+|\\* nack$";
    std::string rs = "^([0-9]+|\\*) nack$";
    std::regex r(rs);

    std::string s1 = "96 nack";
    std::string s2 = "* nack";
    std::string s3 = "96";
    std::cout << std::boolalpha
              << "'" << s1 <<"' match '" << rs << "' : " << std::regex_match(s1, r) << std::endl
              << "'" << s2 <<"'  match '" << rs << "' : " << std::regex_match(s2, r) << std::endl
              << "'" << s3 <<"'      match '" << rs << "' : " << std::regex_match(s3, r) << std::endl;

    return 0;
}
