#include "bitcoinExchange.hpp"
#include <cstdlib>
#include <limits>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    if (this != &src) {
        _data = src._data;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& dbPath) {
    std::ifstream file(dbPath.c_str());
    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(','));
        float rate = std::atof(line.substr(line.find(',') + 1).c_str());
        _data[date] = rate;
    }
}

static bool isValidDate(const std::string& date) {
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2022) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    
    // basic check, not covering all edge cases like 31 days in Feb
    return true;
}


void BitcoinExchange::processInput(const std::string& inputPath) {
    std::ifstream file(inputPath.c_str());
    if (!file.is_open()) {
        throw CouldNotOpenFileException();
    }

    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        try {
            size_t delimiterPos = line.find(" | ");
            if (delimiterPos == std::string::npos) {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            
            std::string dateStr = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 3);

            if (!isValidDate(dateStr)) {
                throw InvalidDateException();
            }

            char* end;
            double value = std::strtod(valueStr.c_str(), &end);

            if (value < 0) {
                throw NotAPositiveNumberException();
            }
            if (value > 1000) {
                throw NumberTooLargeException();
            }

            std::map<std::string, float>::iterator it = _data.lower_bound(dateStr);
            if (it == _data.end() || (it->first != dateStr && it != _data.begin())) {
                --it;
            }
            
            if(it->first > dateStr && it == _data.begin())
            {
                 std::cout << "Error: no data for this date" << std::endl;
                 continue;
            }


            std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;

        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

const char* BitcoinExchange::CouldNotOpenFileException::what() const throw() {
    return "could not open file.";
}

const char* BitcoinExchange::InvalidDateException::what() const throw() {
    return "bad input.";
}

const char* BitcoinExchange::NotAPositiveNumberException::what() const throw() {
    return "not a positive number.";
}

const char* BitcoinExchange::NumberTooLargeException::what() const throw() {
    return "too large a number.";
}