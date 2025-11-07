#include "Span.hpp"
#include <algorithm>

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other) : N(other.N), list(other.list) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		N = other.N;
		list = other.list;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
	if (list.size() >= N)
		throw SpanFullException();
	list.push_back(num);
}

// sort: trie les elements d'un conteneur du plus petit au plus grand
int Span::longestSpan() {
	if (list.size() <= 1)
		throw SpanEmptyException();
	std::vector<int> tmp = list;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}

// je trie et ensuite je compare de droite à gauche
int Span::shortestSpan() {
	if (list.size() <= 1)
		throw SpanEmptyException();
	std::vector<int> tmp = list;
	std::sort(tmp.begin(), tmp.end());
	unsigned int num = tmp[1] - tmp[0];
	for (unsinged int i = 0; i < tmp.size() - 1; i++) {
		if ((tmp[i + 1] - tmp[i]) < num)
			num = (tmp[i + 1] - tmp[i]);
	}
	return num;
}

void Span::addMultipleNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (list.size() <= 1)
		throw SpanEmptyException();
	list.insert(list.end(), begin, end);
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is FULL!";
}

const char* Span::SpanEmptyException::what() const throw() {
	return "Span is EMPTY!";
}