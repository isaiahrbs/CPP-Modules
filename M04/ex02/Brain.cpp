#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain constructor copy called." << std::endl;
	for (int i = 0; i < 100; i++)
			this->idea[i] = other.idea[i];
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	std::cout << "Brain assignment called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->idea[i] = other.idea[i];
	}
	return *this;
}