#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called." << std::endl;
}

Ice::Ice(Ice const& copy) : AMateria(copy) {
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice& Ice::operator=(Ice const& other) {
	std::cout << "Ice assignment operator called." << std::endl;
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}

std::string const& Ice::getType() const {
    return this->_type;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

