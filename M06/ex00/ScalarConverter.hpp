#pragma once

#include <string>
#include <iostream>

enum Type { INT, CHAR, FLOAT, DOUBLE, INVALID };


class ScalarConverter
{
	private:
		static bool isInt(const std::string& literal);
		static bool isChar(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);

		static void printInt(const std::string& literal);
		static void printChar(const std::string& literal);
		static void printFloat(const std::string& literal);
		static void printDouble(const std::string& literal);
		
		static void InvalidInput(const std::string& literal);

	public:
		// ===== Canonical Form =====
		ScalarConverter() = delete;
		ScalarConverter(const std::string& target) = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;

		// ===== Setters =====
		static void convert(const std::string& literal);

		// ===== Getters =====

		// ===== Abstract Functions =====

		// ===== Other Classes/Types =====

		// ===== Friends =====

		// ===== Static Members =====

};
