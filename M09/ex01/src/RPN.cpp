#include "RPN.hpp"
#include <sstream>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &src) {
    *this = src;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src) {
    if (this != &src)
        _stack = src._stack;
    return *this;
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Dépile b puis a (ordre important !), calcule a OP b, empile le résultat.
// On dépile b en premier parce que la pile inverse l'ordre d'empilement.
void RPN::applyOp(char op) {
    if (_stack.size() < 2)
        throw InvalidExprException();

    int b = _stack.top(); _stack.pop(); // deuxième opérande
    int a = _stack.top(); _stack.pop(); // premier opérande

    if (op == '+') _stack.push(a + b);
    else if (op == '-') _stack.push(a - b);
    else if (op == '*') _stack.push(a * b);
    else if (op == '/') {
        if (b == 0)
            throw InvalidExprException(); // division par zéro
        _stack.push(a / b);
    }
}

int RPN::evaluate(const std::string &expr) {
    // Vider la pile au cas où evaluate() est appelé plusieurs fois
    while (!_stack.empty())
        _stack.pop();

    std::istringstream stream(expr);
    std::string token;

    while (stream >> token) {
        // Le sujet garantit que les nombres sont < 10 (un seul chiffre)
        if (token.length() != 1)
            throw InvalidExprException();

        char c = token[0];

        if (std::isdigit(c))
            _stack.push(c - '0'); // convertir le char en int
        else if (isOperator(c))
            applyOp(c);
        else
            throw InvalidExprException(); // token inconnu
    }

    // Une expression RPN valide laisse exactement 1 valeur sur la pile
    if (_stack.size() != 1)
        throw InvalidExprException();

    return _stack.top();
}

const char *RPN::InvalidExprException::what() const throw() {
    return "invalid expression";
}
