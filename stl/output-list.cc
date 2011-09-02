#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <boost/lambda/lambda.hpp>

int main()
{
	std::vector<int> v(3);
	v[0] = 0;
	v[1] = 1;
	v[2] = 2;

	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl;

	std::for_each(v.begin(), v.end(), std::cout<<boost::lambda::_1<<",");
	std::cout << std::endl;

	typedef std::vector<int>::const_iterator CI;
	CI i = v.begin();
	std::cout << *i++;
	for (CI iend=v.end(); i!=iend; ++i)
		std::cout << ", " << *i;
	std::cout << std::endl;

	typedef std::vector<int>::iterator IT;
	IT ii = v.begin();
	std::cout << *ii++;
	std::for_each(ii, v.end(), std::cout<<boost::lambda::constant(",")<<boost::lambda::_1);
	std::cout << std::endl;

	return 0;
}

