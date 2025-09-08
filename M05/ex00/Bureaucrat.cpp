#include "Bureaucrat.hpp"

void Bureaucrat::incrementGrade() {
	try {
		if (_grade <= 1)
			throw "Grade is already maxxed out.";
		else {
			_grade--;
			throw "Added one point to grade!";
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	try {
		if (_grade >= 150)
			throw "Grade is too low.";
		else {
			_grade++;
			throw "Removed a point to grade!";
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}
}

void Bureaucrat::GradeTooHighException() const {
	std::cout << "GRADE TOO HIGH!!!!" << std::endl;
}

void Bureaucrat::radeTooLowException() const {
	std::cout << "GRADE TOO LOW!!!!" << std::endl;
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
	_grade = grade;
	std::cout << "Bureaucrat constructor called." << std::endl;
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
