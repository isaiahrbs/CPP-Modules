#include "Span.hpp"
#include <iostream>

int main() {
    try {
        Span s(5);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(17);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
        
        // should throw error
        s.addNumber(9999);
        return 0;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}