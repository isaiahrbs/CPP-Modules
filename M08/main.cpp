#include <vector>
#include <iostream>
#include <string>

int main()
{

	std::vector<int>::iterator it;
	std::vector<int> values = {1, 2, 3, 4, 5, 6};

	for (int value : values)
		std::cout<<value<<std::endl;
}