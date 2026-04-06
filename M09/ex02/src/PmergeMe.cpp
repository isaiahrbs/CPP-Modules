#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
    *this = src;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
    if (this != &src) {
        _vec = src._vec;
        _deq = src._deq;
    }
    return *this;
}

// Lit les arguments argv[1..argc-1], vérifie que ce sont des entiers positifs,
// et les stocke dans _vec et _deq.
void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        // Vérifier qu'il n'y a que des chiffres (pas de lettres, pas de '-')
        std::string s(argv[i]);
        if (s.empty())
            throw std::runtime_error("empty argument");
        for (size_t j = 0; j < s.size(); j++) {
            if (!std::isdigit(s[j]))
                throw std::runtime_error("not a positive integer: " + s);
        }

        // Convertir en int et vérifier les limites
        long val = std::strtol(s.c_str(), NULL, 10);
        if (val <= 0 || val > 2147483647)
            throw std::runtime_error("value out of range: " + s);

        _vec.push_back((int)val);
        _deq.push_back((int)val);
    }
}

void PmergeMe::run(int argc, char **argv) {
    if (argc < 2)
        throw std::runtime_error("no input provided");

    parseInput(argc, argv);

    // Afficher la séquence AVANT le tri
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << _vec[i];
    }
    std::cout << std::endl;

    // --- Tri avec std::vector ---
    // On utilise clock() pour mesurer le temps en microsecondes
    clock_t startVec = std::clock();
    fordJohnson(_vec);
    clock_t endVec = std::clock();
    double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

    // --- Tri avec std::deque ---
    clock_t startDeq = std::clock();
    fordJohnson(_deq);
    clock_t endDeq = std::clock();
    double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    // Afficher la séquence APRÈS le tri (on prend _vec comme référence)
    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); i++) {
        if (i > 0) std::cout << " ";
        std::cout << _vec[i];
    }
    std::cout << std::endl;

    // Afficher les temps
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
