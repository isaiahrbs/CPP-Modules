#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
		const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
        
        
    public:
		std::string getName() const;
        int getSignLimit() const;
        int getExecLimit() const;
        bool      signedStatus() const;

        void      beSigned(const Bureaucrat& ref);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

        Form();
		Form(const Form& other);
        Form(const std::string& name, const int signGrade, const int execGrade);
        Form& operator=(const Form& other);
        ~Form();
};

std::ostream& operator<<(std::ostream &os, const Form& form);