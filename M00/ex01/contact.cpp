#include "contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setContact(std::string fn, std::string ln,
							std::string nick, std::string phonenum,
							std::string secret) {
	this->firstName = fn;
	this->lastName = ln;
	this->nickName = nick;
	this->phoneNumber = phonenum;
	this->darkestSecret = secret;
}

static std::string formatField(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

// the setw is just to set a limit of max 10 chars per variables
void Contact::displayShort(int index) const {
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << formatField(firstName) << "|"
				<< std::setw(10) << formatField(lastName) << "|"
				<< std::setw(10) << formatField(nickName) << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
