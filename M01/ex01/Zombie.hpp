#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void	announce() const;
		void	setName(const std::string& name);
};

#endif