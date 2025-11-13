#include "Span.hpp"
#include <iostream>

int main() {
    Span s(5);
    s.addNumber(6);
    s.addNumber(3);
    s.addNumber(17);
    s.addNumber(9);
    s.addNumber(11);
    std::cout << s.shortestSpan() << std::endl;
    std::cout << s.longestSpan() << std::endl;
    return 0;
}