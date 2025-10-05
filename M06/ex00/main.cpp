#include "ScalarConverter.hpp"

int main() {
	ScalarConverter::convert("10");
	ScalarConverter::convert("20.2f");
	ScalarConverter::convert("a");
	ScalarConverter::convert("30.333");
	ScalarConverter::convert("caca");
}