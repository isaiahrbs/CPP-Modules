#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm
{
	private:
		// ===== Private Members =====
		std::string target;
		

	protected:
		// ===== Protected Members =====

	public:
		// ===== Canonical Form =====
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		// ===== Setters =====

		// ===== Getters =====

		// ===== Abstract Functions =====
		void execute(Bureaucrat const & executor) const;

		// ===== Other Classes/Types =====

		// ===== Friends =====

		// ===== Static Members =====

};
