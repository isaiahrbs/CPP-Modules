#include "Weapon.hpp"

/*
en gros c'est egal a :

Weapon::Weapon(const std::string& type) {
    this->type = type;
}
*/

Weapon::Weapon(const std::string& type) : type(type) {
}

//seting up the gettype function shit
const std::string& Weapon::getType() const {
	return type;
}

//then i set my shit up
void	Weapon::setType(const std::string& newType) {
	type = newType;
}