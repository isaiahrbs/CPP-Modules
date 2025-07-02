#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		currentIndex;
		int		totalContacts;

	public:
		PhoneBook();
		void	addContact();
		void	searchContact() const;
};

#endif