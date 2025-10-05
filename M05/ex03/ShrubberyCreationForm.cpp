#include "ShrubberyCreationForm.hpp"
#include <fstream>

// ===== Canonical Form =====
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// ===== Abstract Functions =====
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!signedStatus())
		throw NotSigned();
	if (executor.getGrade() > getExecLimit())
		GradeTooLowException();
	std::ofstream newFile((target + "_shrubbery").c_str());
	if (!newFile.is_open())
		throw CannotOpenFile();
	    newFile <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";
	newFile.close();
	std::cout << "Shrubbery file has been created:" << target + "_shrubbery" << std::endl;
}