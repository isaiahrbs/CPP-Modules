#pragma once

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string idea[100];
		
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
};