#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		Zombie(std::string name);
		~Zombie();
		void	announce() const;
};

#endif