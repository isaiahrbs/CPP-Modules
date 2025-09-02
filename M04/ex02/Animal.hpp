#pragma once

#include <iostream>
#include <string>

class Animal {
	protected:
		std::string type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const = 0; // when you set a virtual fonction to 0 in cpp it says to cpp : "i only serve to be virtual i contain nothing" there has to be a subclass
};