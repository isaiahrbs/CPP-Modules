#include "Form.hpp"
#include "Bureaucrat.hpp"

std::string Form::getName() const {
	return this->_name;
}

int Form::getSignLimit() const {
	return _gradeToSign;
}

int Form::getExecLimit() const {
	return _gradeToExecute;
}

bool Form::signedStatus() const {
	return _isSigned;
}

void Form::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	if (this->_isSigned) {
		throw AlreadySignedException();
	}
	this->_isSigned = true;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Form : Grade is too low!";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form : Grade is too high!";
}

const char* Form::AlreadySignedException::what() const throw() {
    return "Form is already signed!";
}

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(100), _gradeToExecute(60) {
	std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Copy Form constructor called." << std::endl;
}

Form::Form(const std::string& name, const int signGrade, const int execGrade)
    : _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(execGrade) {
	std::cout << "Form constructor called." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw(GradeTooHighException());

	if (signGrade > 150 || execGrade > 150)
		throw(GradeTooLowException());
}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called." << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Form& form) {
	os << form.getName()
		<< ", form sign grade " << form.getSignLimit()
		<< ", execute grade " << form.getExecLimit()
		<< ", signed: ";
	if (form.signedStatus())
		os << "yes";
	else
		os << "no";
	return os;
}