#include <vector>
# include "easyfind.h"

int main()
{
	std::vector<int> vec;
	std::vector<int>::iterator ans;

	for (int i=0; i < 100; i++) {vec.push_back(i*2);}

	try {
		ans = easyfind(vec, 8);
		std::cout << *ans << std::endl;
		std::cout << std::endl;

		ans = easyfind(vec, -1);
		std::cout << *ans << std::endl;
		std::cout << std::endl;
	} catch (...) {
		std::cerr << "Error: Invalid value" << std::endl;
	}
}