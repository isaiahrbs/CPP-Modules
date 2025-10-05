#pragma once
#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
		const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
        
        
    public:
		// -- constructors and destructors
		AForm();
		AForm(const AForm& other);
		AForm(const std::string& name, const int signGrade, const int execGrade);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		// -- setters
        void      beSigned(const Bureaucrat& ref);

		// -- getters 
		std::string getName() const;
        int getSignLimit() const;
        int	getExecLimit() const;
        bool      signedStatus() const;

		// -- abstract function
		virtual void execute(Bureaucrat const & executor) const = 0;

		// -- other objects
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NotSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class CannotOpenFile : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm& form);
