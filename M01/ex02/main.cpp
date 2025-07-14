#include <iostream>
#include <string>

int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;
	/*
	& c'est un alias en gros il a la meme memoire que brain et si
	je le modifie ca modifie le brain car c'est just un alias
	c'est la meme chose les 2 en gros
	*/

	// adwess memoar
	std::cout << "Address of brain:      " << &brain << std::endl;
	std::cout << "Address held by PTR:   " << stringPTR << std::endl;
	std::cout << "Address held by REF:   " << &stringREF << std::endl;

	// les valeurs
	std::cout << "Value of brain:        " << brain << std::endl;
	std::cout << "Value pointed by PTR:  " << *stringPTR << std::endl;
	std::cout << "Value pointed by REF:  " << stringREF << std::endl;

	return 0;
}