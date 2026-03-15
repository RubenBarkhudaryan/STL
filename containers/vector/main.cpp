#include "./vector.h"

int main()
{
	rub::vector<int> vct = {1,2,3,4,5};

	std::cout << "Forward: ";
	for (rub::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	std::cout << "Reverse: ";
	for (rub::vector<int>::reverse_iterator it = vct.rbegin(); it != vct.rend(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	const rub::vector<int>& cvct = vct;
	std::cout << "Const forward: ";
	for (rub::vector<int>::const_iterator it = cvct.cbegin(); it != cvct.cend(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';

	rub::vector<int>::iterator it = vct.begin();
	it += 2;
	std::cout << "it += 2 -> " << *it << '\n';
	std::cout << "it[1] -> " << it[1] << '\n';
	std::cout << "distance(end, begin) -> " << (vct.end() - vct.begin()) << '\n';

	try
	{
		vct.at(5);
	}
	catch(const rub::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}