#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// required grades: sign 145, exec 137
class ShrubberyCreationForm : public AForm
{
private:
	// ===== Private Members =====
	std::string target;

protected:
	// ===== Protected Members =====

public:
	// ===== Canonical Form =====
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	// ===== Setters =====

	// ===== Getters =====

	// ===== Abstract Functions =====
	void execute(Bureaucrat const & executor) const;

	// ===== Other Classes/Types =====

	// ===== Friends =====

	// ===== Static Members =====

};
