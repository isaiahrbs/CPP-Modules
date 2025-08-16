#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat has been constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Copy Cat has been constructed." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "CAT: Copy assignment called." << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
