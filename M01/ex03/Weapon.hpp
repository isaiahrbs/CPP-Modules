#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	private:
		std::string type;

	public:
		Weapon(const std::string& type);
		const std::string& getType() const;
		void setType(const std::string& type);
};

#endif

/*
 la raison de pk jutilise & c'est pour pas que ca crée de copie de la stirng
 en cpp c'est mieux de direct prendre lhabitude de faire ca pour economiser de lespace
 
 un alias ne peut pas tre vide

 un pointeur peut etre vide
*/