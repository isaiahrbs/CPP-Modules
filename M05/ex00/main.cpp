#include "Bureaucrat.hpp"
#include <unistd.h>


int main() {
	Bureaucrat b1("Karim", 140);
	
	Bureaucrat b2;
	Bureaucrat b3(b1);
	Bureaucrat b4("test", 50);
	
	std::string name;
	int grade;
	//std::cout << b2 << std::endl;

	// B2
	grade = b2.getGrade();
	name = b2.getName();
	std::cout << "Name : " << name << std::endl;
	std::cout << "Grade : " << grade << std::endl;

	sleep(4);

	for (int i = 0; i < 10; i++) {
		b2.decrementGrade();
	}
	
	//std::cout << b3 << std::endl;
		
	sleep(4);

	//B1
	grade = b1.getGrade();
	name = b1.getName();
	std::cout << "Name : " << name << std::endl;
	std::cout << "Grade : " << grade << std::endl;

	for (int i = 0; i < 10; i++) {
		b1.incrementGrade();
	}

	//B3
	grade = b3.getGrade();
	name = b3.getName();
	std::cout << "Grade : " << grade << std::endl;
	std::cout << "Name : " << name << std::endl;

	sleep(4);
	b3 = b4;
	grade = b3.getGrade();
	name = b3.getName();
	std::cout << "Final test" << std::endl;
	std::cout << "Grade : " << grade << std::endl;
	std::cout << "Name : " << name << std::endl;
	
}