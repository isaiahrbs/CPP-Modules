#include "AMateria.hpp"

AMateria::AMateria() {
	std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(std::string const& type) {
	std::cout << "AMateria with type constructor called." << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const& copy) {
	std::cout << "AMateria copy constructor called." << std::endl;
	this->_type = copy._type;
}

AMateria& AMateria::operator=(AMateria const& other) {
	std::cout << "AMateria assignment operator called." << std::endl;
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria destructor called." << std::endl;
}

std::string const& AMateria::getType() const {
	return (this->_type);
}

// useless cuz its virtual
void AMateria::use(ICharacter& target) {
	std::cout << "AMateria is using on " << target.getName() << std::endl;
}
