#include "ScalarConverter.hpp"
#include <cstdlib>

bool ScalarConverter::isInt(const std::string& literal) {
	size_t i = 0;
	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while (i < literal.size()) {
		if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isChar(const std::string& literal) {
    return literal.size() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (literal.empty())
        return false;
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < literal.size()) {
        if (std::isdigit(literal[i])) {
            hasDigit = true;
        } else if (literal[i] == '.') {
            if (hasDot)
                return false;// if a second dot found it returns false
            hasDot = true;
        } else if (literal[i] == 'f' && i == literal.size() - 1 && hasDigit) { // if last character if f and there is at least 1 number
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    size_t i = 0;
    bool hasDot = false;
    bool hasDigit = false;

    if (literal.empty())
        return false;
    if (literal[i] == '+' || literal[i] == '-')
        i++;

    while (i < literal.size()) {
        if (std::isdigit(literal[i])) {
            hasDigit = true;
        } else if (literal[i] == '.') {
            if (hasDot)
                return false; // only one dot allowed
            hasDot = true;
        } else {
            return false; // invalid character for double
        }
        i++;
    }
    return hasDigit && hasDot; // must have at least one digit and one dot
}

void ScalarConverter::printInt(const std::string& literal) {
	int value = std::atoi(literal.c_str());
	std::cout << "Integer: " << value << std::endl;
}

void ScalarConverter::printChar(const std::string& literal) {
	std::cout << "Char: " << literal << std::endl;
}

void ScalarConverter::printFloat(const std::string& literal) {
	float value = std::atof(literal.c_str());
	std::cout << "float: " << value << "f" << std::endl;
}

void ScalarConverter::printDouble(const std::string& literal) {
	double value = std::atof(literal.c_str());
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::InvalidInput(const std::string& literal) {
	std::cout << literal << " : is an invalid input." << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	if (isInt(literal))
		printInt(literal);
	else if (isFloat(literal))
		printFloat(literal);
	else if (isChar(literal))
		printChar(literal);
	else if (isDouble(literal))
		printDouble(literal);
	else
		InvalidInput(literal);
}
