#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal has been constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "Copy WrongAnimal has been constructed." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WRONGANIMAL: Copy assignment called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}