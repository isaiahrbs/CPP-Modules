#include "bitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src)
        _data = src._data;
    return *this;
}

// Charge le fichier CSV (format: date,rate) dans la map _data.
// La première ligne (header) est ignorée.
void BitcoinExchange::loadDatabase(const std::string &dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open())
        throw CouldNotOpenFileException();

    std::string line;
    std::getline(file, line); // skip "date,exchange_rate"

    while (std::getline(file, line)) {
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        double rate = std::atof(line.substr(comma + 1).c_str());
        _data[date] = rate;
    }
}

// Vérifie que la date respecte le format YYYY-MM-DD et que les valeurs ont du sens.
// On ne vérifie pas les cas comme "31 février" mais ça couvre 99% des erreurs.
static bool isValidDate(const std::string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Vérifier que toutes les positions sont bien des chiffres
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31)     return false;

    return true;
}

// Lit le fichier d'entrée ligne par ligne.
// Format attendu : "YYYY-MM-DD | valeur"
// Pour chaque ligne valide, on cherche le prix BTC du jour le plus proche.
void BitcoinExchange::processInput(const std::string &inputPath) {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open())
        throw CouldNotOpenFileException();

    std::string line;
    std::getline(file, line); // skip "date | value"

    while (std::getline(file, line)) {
        // Chercher le séparateur " | "
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr  = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);

        if (!isValidDate(dateStr)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Convertir la valeur (peut être un float ou un int)
        char *end;
        double value = std::strtod(valueStr.c_str(), &end);
        if (*end != '\0' && *end != '\n') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // lower_bound retourne un itérateur vers la première date >= dateStr.
        // Si on a un match exact, parfait. Sinon, on recule d'un cran pour
        // obtenir la date la plus proche AVANT.
        std::map<std::string, double>::iterator it = _data.lower_bound(dateStr);

        if (it == _data.end() || it->first != dateStr) {
            if (it == _data.begin()) {
                // Toutes les dates du CSV sont après la date demandée
                std::cout << "Error: no data for this date." << std::endl;
                continue;
            }
            --it; // on prend la date juste avant
        }

        std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
    }
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw() {
    return "could not open file.";
}
