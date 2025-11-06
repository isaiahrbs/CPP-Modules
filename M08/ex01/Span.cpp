#include "Span.hpp"
#include <algorithm>

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other) : N(other.N){}

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

int Span::shortestSpan() {
	if (list.size() <= 1)
		throw SpanEmptyException();
	// LEFT OFF HERE!!!!
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is FULL!";
}

const char* Span::SpanEmptyException::what() const throw() {
	return "Span is EMPTY!";
}