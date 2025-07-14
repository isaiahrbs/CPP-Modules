#include "Zombie.hpp"

void	Zombie::announce() const {
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name) {
	this->name = name;
}

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed 💀" << std::endl;
}
