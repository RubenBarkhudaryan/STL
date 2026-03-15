#include "./vector.hpp"
#include <cassert>

int main()
{
	rub::vector<int> vct = {1,2,3,4,5};
	assert(vct.size() == 5);

	std::cout << "Forward: ";
	int expected = 1;
	for (rub::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
	{
		assert(*it == expected++);
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	std::cout << "Reverse: ";
	expected = 5;
	for (rub::vector<int>::reverse_iterator it = vct.rbegin(); it != vct.rend(); ++it)
	{
		assert(*it == expected--);
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	const rub::vector<int>& cvct = vct;
	std::cout << "Const forward: ";
	expected = 1;
	for (rub::vector<int>::const_iterator it = cvct.cbegin(); it != cvct.cend(); ++it)
	{
		assert(*it == expected++);
		std::cout << *it << ' ';
	}
	std::cout << '\n';

	rub::vector<int>::iterator it = vct.begin();
	it += 2;
	assert(*it == 3);
	assert(it[1] == 4);
	assert((vct.end() - vct.begin()) == 5);
	std::cout << "it += 2 -> " << *it << '\n';
	std::cout << "it[1] -> " << it[1] << '\n';
	std::cout << "distance(end, begin) -> " << (vct.end() - vct.begin()) << '\n';

	bool out_of_range_thrown = false;
	try
	{
		vct.at(5);
	}
	catch(const rub::exception& e)
	{
		out_of_range_thrown = true;
		std::cerr << e.what() << '\n';
	}
	assert(out_of_range_thrown);
}