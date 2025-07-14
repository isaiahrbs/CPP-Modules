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

//returns a pointer to a new zombie obj
Zombie* newZombie(std::string name) {
	return new Zombie(name);
}

void randomChump(std::string name) {
	Zombie zombie(name);
	zombie.announce();
}