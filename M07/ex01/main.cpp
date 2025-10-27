#include "iter.hpp"

void str_toupper(std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = std::toupper(str[i]);
	}
}

void times_ten(size_t& num) {
	num *= 10;
}

int main() {
	// test variables
	std::string array[] = {"test string", "other string", "another string"};

	//before 
	for (size_t i = 0; i < 3; i++) {
		std::cout << array[i] << std::endl;
	}

	iter(array, 3, str_toupper);

	//after 
	for (size_t i = 0; i < 3; i++) {
		std::cout << array[i] << std::endl;
	}

	//--------------------------------------

	size_t nums[] = {1, 2, 3, 4, 5};

	//before
	for (size_t i = 0; i < 5; i++) {
		std::cout << nums[i] << std::endl;
	}

	iter(nums, 5, times_ten);

	//after
	for (size_t i = 0; i < 5; i++) {
		std::cout << nums[i] << std::endl;
	}
}