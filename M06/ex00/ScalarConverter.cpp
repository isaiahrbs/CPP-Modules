#include "ScalarConverter.hpp"

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
            if (hasDot) return false;
            hasDot = true;
        } else if (literal[i] == 'f' && i == literal.size() - 1 && hasDigit) {
            return true;
        } else {
            return false;
        }
        i++;
    }
    return false;
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
