#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat has been constructed." << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Copy Cat has been constructed." << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "CAT: Copy assignment called." << std::endl;
    if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called." << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
