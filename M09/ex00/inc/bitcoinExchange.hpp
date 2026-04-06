#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>

// BitcoinExchange lit une base de données de prix BTC (CSV) et un fichier
// d'entrée (date | quantité), puis calcule la valeur en multipliant les deux.
// Pour une date absente du CSV, on utilise le prix de la date la plus proche AVANT.

class BitcoinExchange {
private:
    // On stocke date -> taux dans une map.
    // Les maps sont triées par clé (ici les dates YYYY-MM-DD, ordre lexicographique = ordre chronologique)
    std::map<std::string, double> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &src);

    void loadDatabase(const std::string &dbPath);
    void processInput(const std::string &inputPath);

    class CouldNotOpenFileException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

#endif
