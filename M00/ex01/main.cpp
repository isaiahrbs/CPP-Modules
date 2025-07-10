#include "phonebook.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cin.clear();
				clearerr(stdin);
				std::cout << "\n";
				continue;
			}
		}
		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT") {
			break;
		}
		else {
			std::cout << "Invalid command." << std::endl;
		}
	}

	return 0;
}
