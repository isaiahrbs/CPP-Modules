#include "PmergeMe.hpp"
#include <iostream>

// Usage : ./PmergeMe 3 5 9 7 4 1 8 2 6
// Tous les arguments doivent être des entiers positifs.

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integers...>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.run(argc, argv);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
