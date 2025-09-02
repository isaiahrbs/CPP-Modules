#pragma once
#include <iostream>
#include <string>

class AMateria; // its telling the compiler that there will be a AMateria somewhere in the projects called, if it isn't called there will be a compilation error

class ICharacter
{
	public:
		virtual const std::string& getName() const = 0;
		virtual void equip(AMateria* power) = 0;
		virtual void unequip(int inventoryNum) = 0;
		virtual void use(int idx, ICharacter& character) = 0;

		virtual ~ICharacter() {};
};
