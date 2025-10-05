#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}
	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), target(other.target) {
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!signedStatus())
		throw NotSigned();
	if (executor.getGrade() > getExecLimit())
		throw GradeTooLowException();
	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized!" << std::endl;
	else
		std::cout << target << " robotomy failed..." << std::endl;
}