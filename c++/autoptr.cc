#include <list>
#include <memory>

int main()
{
	std::auto_ptr<int> pi(new int(10));

	typedef std::auto_ptr<int> Auto_int_ptr;

	std::list<Auto_int_ptr> list;

	list.push_back(pi);

	return 0;
}
