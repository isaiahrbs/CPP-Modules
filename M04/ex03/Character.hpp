#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_inventory[4];

	public:
		const std::string& getName () const;
		void equip(AMateria* power);
		void unequip(int inventoryNum);
		void use(int idx, ICharacter& character);
		bool inInventory(AMateria* ref);

		Character();
		Character(const std::string& name);
		Character(const Character& copy);
		Character& operator=(const Character& other);
		~Character();
};
