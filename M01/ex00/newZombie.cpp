#include "Zombie.hpp"

//returns a pointer to a new zombie obj
Zombie* newZombie(std::string name) {
	return new Zombie(name);
}