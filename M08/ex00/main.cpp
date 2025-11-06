#include "easyfind.hpp"
#include <iostream>
#include <string>

int main()
{
	std::vector<int> list; // une liste vide

	// ajouter des valeurs (comme push_swap, on ajoute des valeurs a la fin de la liste)
	list.push_back(42);
	list.push_back(51);
	list.push_back(13);
	list.push_back(60);
	list.push_back(9000);
	list.push_back(0);

	std::vector<int>::iterator it = easyfind(list, 0);
	/*
		•c'est une meilleure approche car si j'ai `0` dans la liste et que je fais
		- if (*it), ca ne va pas marcher
	*/
	 if (it != list.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Nothing found" << std::endl;

	std::cout << *it << std::endl;

	std::vector<std::string> nameList;
	nameList.push_back("42School");
	nameList.push_back("Isaiah");
	nameList.push_back("Lisa");
	nameList.push_back("Dimitri NGUYEN GONG");

	std::vector<std::string>::iterator pos = std::find(nameList.begin(), nameList.end(), "Dimicouille");

	if (pos != nameList.end())
		std::cout << "FOUND" << std::endl;
	else
		std::cout << "NOT FOUND" << std::endl;

}