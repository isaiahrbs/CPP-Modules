#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;	
}

Intern::~Intern() {

}

const char* Intern::InvalidArgument::what() const throw() {
	return "Not a valid Form";
}

// the first one is the type of form, the second one is the act of the form
AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	std::string form_Names[] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	for (int i = 0; i < 3; i++) {
		if (name == form_Names[i]) {
			std::cout << "Intern created : " << form_Names[i] + "." << std::endl;
			switch (i) {
				case 0: return new ShrubberyCreationForm(target);
				case 1: return new RobotomyRequestForm(target);
				case 2: return new PresidentialPardonForm(target);
			}
		}
	}
	throw InvalidArgument();
}