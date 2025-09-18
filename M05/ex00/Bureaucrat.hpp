#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int   _grade; // 1 - 150 : limit

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};

		void incrementGrade();
		void decrementGrade();

		std::string getName() const;
		int			getGrade() const;

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);