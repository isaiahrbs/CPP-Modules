#include <iostream>
#include "Array.hpp"

int	main() {
	std::cout << "----test1----" << std::endl;
	Array<int> a(3);
	a[0] = 2;
	a[1] = 4;
	std::cout << "a[0] : " << a[0] << std::endl;
	Array<int> b = a;
	std::cout << "b[1] : " << b[1] << std::endl;
	Array<int> c(b);
	std::cout << "c[1] : " << c[1] << std::endl;
	std::cout << "c.size : " << c.size() << std::endl;

	std::cout << "\n----test2 out of bounds----" << std::endl;
    std::cout << "Test1" << std::endl;
	try{
		Array<std::string> test(1);
		test[4] = "lol";
		std::cout << test[4] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n----test3----" << std::endl;
	Array<std::string> str(3);
	try {
		str[0] = "hello";
		str[1] = "world";
		str[2] = "!";
		std::cout << str[0] << " " << str[1] << str[2] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----test4----" << std::endl;
	Array<int> gg(2);
	gg[0] = 5;
	gg[1] = 2;
	const Array<int> const_str(gg);
	std::cout << "gg[0] : " << const_str[0] << std::endl;
	std::cout << "gg[1] : " << const_str[1] << std::endl;
}