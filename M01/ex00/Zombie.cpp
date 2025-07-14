#include "Zombie.hpp"

void	Zombie::announce() const {
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed 💀" << std::endl;
}
