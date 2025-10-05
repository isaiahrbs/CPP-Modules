#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultAForm"), _isSigned(false), _gradeToSign(100), _gradeToExecute(60) {
	std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Copy AForm constructor called." << std::endl;
}

AForm::AForm(const std::string& name, const int signGrade, const int execGrade)
	: _name(name), _isSigned(false), _gradeToSign(signGrade), _gradeToExecute(execGrade) {
	std::cout << "AForm constructor called." << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw(GradeTooHighException());

	if (signGrade > 150 || execGrade > 150)
		throw(GradeTooLowException());
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called." << std::endl;
}

void AForm::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > this->_gradeToSign) {
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

std::string AForm::getName() const {
	return this->_name;
}

int AForm::getSignLimit() const {
	return _gradeToSign;
}

int AForm::getExecLimit() const {
	return _gradeToExecute;
}

bool AForm::signedStatus() const {
	return _isSigned;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "AForm : Grade is too high!";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "AForm : Grade is too low!";
}

const char*	AForm::NotSigned::what() const throw() {
	return "AForm : Not signed!";
}

const char*	AForm::CannotOpenFile::what() const throw() {
	return "AForm : Cannot open file!";
}

std::ostream& operator<<(std::ostream &os, const AForm& aform) {
	os << aform.getName()
		<< ", aform sign grade " << aform.getSignLimit()
		<< ", execute grade " << aform.getExecLimit()
		<< ", signed: ";
	if (aform.signedStatus())
		os << "yes";
	else
		os << "no";
	return os;
}