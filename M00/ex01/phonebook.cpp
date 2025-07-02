#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
    currentIndex = 0;
    totalContacts = 0;
}

void PhoneBook::addContact() {
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    contacts[currentIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

void PhoneBook::searchContact() const {
	if (totalContacts == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}
	// i still need the setw because it adds spaces if there is under than 10chars
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < totalContacts; i++) {
		contacts[i].displayShort(i);
	}

	std::cout << "Enter index (0 to " << totalContacts - 1 << "): ";
	int index;
	std::cin >> index;
	std::cin.ignore(); // ignore newline

	if (std::cin.fail() || index < 0 || index >= totalContacts) {
		std::cin.clear();
		std::cout << "Invalid index!" << std::endl;
		return;
	}

	contacts[index].displayFull();
}
