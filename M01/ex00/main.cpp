#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int main() {
	randomChump("StackZombie");

	Zombie* testZombie = newZombie("testZombie");
	testZombie->announce();
	//std::cout << "caca" << std::endl;
	delete testZombie;

	return 0;
}

/*
	I learned that destructors are called at the end of the functions that 
	the constructor was called in and also it is called if i delete something
	if i delete a class well it is going to call the destructor function
*/