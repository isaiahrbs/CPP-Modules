#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
		// ===== Private Members =====
		

	protected:
		// ===== Protected Members =====

	public:
		// ===== Canonical Form =====
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		// ===== Setters =====
		AForm* makeForm(const std::string& name, const std::string& target);

		// ===== Getters =====

		// ===== Abstract Functions =====

		// ===== Other Classes/Types =====
		class InvalidArgument : public std::exception {
			public:
				const char* what() const throw();
		};

		// ===== Friends =====

		// ===== Static Members =====
};
