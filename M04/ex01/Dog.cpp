#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog has been constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Copy Dog has been constructed." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "DOG: Copy assignment called." << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog Destructor called." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Bark!" << std::endl;
}
