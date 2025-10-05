#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::incrementGrade() {
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << this->_name << " couldn't sign : " << form.getName() << " : " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const {
    try {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!"; 
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}


Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(40) {
	std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat " << _name << " constructor called." << std::endl;
	std::cout << "pipi" << std::endl;
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade >= 150)
		throw(GradeTooLowException());
	std::cout << "pipi2" << std::endl;
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
	std::cout << "Bureaucrat constructor called." << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other) {
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return os;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}
