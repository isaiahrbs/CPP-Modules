#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <typeinfo>

Base* generate(void) {
	int r = std::rand() % 3;

	if (r == 0)
		return new BaseA;
	else if (r == 1)
		return new BaseB;
	else (r == 2)
		return new BaseC;
}

void printType(Base* ptr) {
	if (dynamic_cast<BaseA*>(ptr))
		std::cout << "Type: BaseA" << std::endl;
	else if (dynamic_cast<BaseB*>(ptr))
		std::cout << "Type: BaseB" << std::endl;
	else if (dynamic_cast<BaseC*>(ptr))
		std::cout << "Type: BaseC" << std::endl;
	else
		std::cout << "Type: Unknown" << std::endl;
}

void	identify(Base &p) {
	try {
		(void)dynamic_cast<BaseA&>(p);
		std::cout << "A\n";
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<BaseB&>(p);
		std::cout << "B\n";
	}
	catch (std::exception &e) {}
	try {
		(void)dynamic_cast<BaseC&>(p);
		std::cout << "C\n";
	}
	catch (std::exception &e) {}
}