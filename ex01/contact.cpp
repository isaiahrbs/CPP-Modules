#include "Contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setInfo(const std::string& fn, const std::string& ln,
						const std::string& nick, const std::string& phone,
						const std::string& secret) {
	firstName = fn;
	lastName = ln;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string Contact::getShort(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void Contact::displayRow(int index) const {
	std::cout << "|" << std::setw(10) << index
			<< "|" << std::setw(10) << getShort(firstName)
			<< "|" << std::setw(10) << getShort(lastName)
			<< "|" << std::setw(10) << getShort(nickname)
			<< "|" << std::endl;
}
