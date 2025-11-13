#pragma once

#include <string>
#include <exception>
#include <iostream>
#include <vector>

/*

• Exemple: [6, 3, 17, 9, 11]
• shortestSpan() = plus petite différence = |9-11| = 2
• longestSpan() = plus grande différence = |17-3| = 14

*/
class Span
{
private:
	// ===== Private Members =====
	unsigned int N;
	std::vector<int> list;

protected:
	// ===== Protected Members =====

public:
	// ===== Canonical Form =====
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// ===== Setters =====
	void addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void addNumber(int num);

	// ===== Getters =====
	int longestSpan();
	int shortestSpan();

	// ===== Abstract Functions =====

	// ===== Other Classes/Types =====
	class SpanFullException : public std::exception {
		virtual const char* what() const throw();
	};

	class SpanEmptyException : public std::exception {
		virtual const char* what() const throw();
	};

	// ===== Friends =====

	// ===== Static Members =====

};
