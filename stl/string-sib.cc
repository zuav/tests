#include <iostream>
#include <string>

int main()
{
	std::string s("b2bua@system.jabber.unison.org");

	std::cout << s.substr(s.find(".")+1) << std::endl;

	return 0;
}
