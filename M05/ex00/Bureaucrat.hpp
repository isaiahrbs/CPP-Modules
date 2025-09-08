#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int   _grade; // 1 - 150 : limit

	public:
		void incrementGrade();
		void decrementGrade();

		void GradeTooHighException() const;
		void radeTooLowException() const;
		std::string getName() const;
		int			getGrade() const;

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);
		~Bureaucrat();
};
