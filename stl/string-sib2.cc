#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string s = argv[1];

	std::cout << "s =      " << s << std::endl
              << "substr = " << s.substr(0, s.find("@")) << std::endl;

	return 0;
}
