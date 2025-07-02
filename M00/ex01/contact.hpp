#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		void	setContact(std::string fn, std::string ln, std::string nick, std::string phonenum, std::string secret);
		void	displayFull() const;
		void	displayShort(int index) const;
};

#endif