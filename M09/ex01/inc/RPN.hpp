#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <exception>

// Calculatrice en Notation Polonaise Inversée (RPN / postfixe).
//
// En RPN, les opérateurs viennent APRÈS les opérandes.
// Exemple : "3 4 +" vaut 7  (et non pas "3 + 4")
//           "5 1 2 + 4 * + 3 -" vaut 14
//
// L'algorithme : on lit token par token.
//   - Si c'est un nombre -> on l'empile.
//   - Si c'est un opérateur -> on dépile deux nombres, on calcule, on empile le résultat.
// À la fin, il doit rester exactement 1 valeur sur la pile = le résultat.
//
// Conteneur utilisé : std::stack (LIFO, parfait pour ça)

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    void applyOp(char op);         // dépile 2 valeurs, applique l'op, empile le résultat

public:
    RPN();
    RPN(const RPN &src);
    ~RPN();
    RPN &operator=(const RPN &src);

    // Évalue l'expression RPN passée en string, retourne le résultat.
    // Lève InvalidExprException si l'expression est malformée.
    int evaluate(const std::string &expr);

    class InvalidExprException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif
