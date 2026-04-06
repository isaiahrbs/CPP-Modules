#include "RPN.hpp"
#include <iostream>

// Usage : ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
// Les tokens doivent être séparés par des espaces.
// Les nombres sont des entiers à un seul chiffre (< 10).

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./RPN \"<expression>\"" << std::endl;
        return 1;
    }

    try {
        RPN calc;
        std::cout << calc.evaluate(argv[1]) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
