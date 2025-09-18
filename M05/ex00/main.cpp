#include "Bureaucrat.hpp"
#include <unistd.h>


int main() {
	std::cout << "[--------------Test #1--------------]" << std::endl;
	try {
		Bureaucrat e("Eminem", 160);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "[--------------Test #2--------------]" << std::endl;
	try {
		Bureaucrat l("Link", 160);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "[--------------Test #3--------------]" << std::endl;
	try {
		Bureaucrat l("Zelda", 150);
		l.decrementGrade();
		// it skips this one because as soon as there is a throw, it goes to the catch block
		Bureaucrat b("Bob", 170);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}