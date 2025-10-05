#pragma once

#include "AForm.hpp"

// Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm
{
private:
	// ===== Private Members =====
	std::string target;

protected:
	// ===== Protected Members =====

public:
	// ===== Canonical Form =====
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	// ===== Setters =====

	// ===== Getters =====

	// ===== Abstract Functions =====
	void execute(Bureaucrat const & executor) const;

	// ===== Other Classes/Types =====

	// ===== Friends =====

	// ===== Static Members =====

};
