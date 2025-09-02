#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat has been constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "Copy WrongCat has been constructed." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WRONGCAT: Copy assignment called." << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow!" << std::endl;
}