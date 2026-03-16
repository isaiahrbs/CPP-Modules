#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>

class BitcoinExchange {
private:
    std::map<std::string, float> _data;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &src);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &src);

    void loadDatabase(const std::string& dbPath);
    void processInput(const std::string& inputPath);

    class CouldNotOpenFileException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidDateException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NotAPositiveNumberException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NumberTooLargeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif