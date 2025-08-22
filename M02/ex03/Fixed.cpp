#include "Fixed.hpp"
#include <cmath>
#include <iostream>


// Constructeurs & Canonical
Fixed::Fixed() : _value(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
    //std::cout << "Int constructor called" << std::endl;
    _value = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
    //std::cout << "Float constructor called" << std::endl;
    _value = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &objcopy) {
    //std::cout << "Copy constructor called" << std::endl;
    _value = objcopy._value;
}

Fixed &Fixed::operator=(const Fixed &other) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other._value;
    return *this;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

// Accesseurs
int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(const int raw) {
    _value = raw;
}

float Fixed::toFloat() const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

// Opérateurs arithmétiques
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._value = _value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._value = _value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    // Pour éviter la perte de précision, on cast en int64_t
    result._value = (int64_t)_value * (int64_t)other._value / (1 << _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    // Pour éviter la perte de précision, on cast en int64_t
    result._value = ((int64_t)_value << _fractionalBits) / other._value;
    return result;
}

// Incrémentation/Décrémentation
Fixed &Fixed::operator++() { // pré-incrément
    ++_value;
    return *this;
}
Fixed Fixed::operator++(int) { // post-incrément
    Fixed tmp(*this);
    ++_value;
    return tmp;
}
Fixed &Fixed::operator--() { // pré-décrément
    --_value;
    return *this;
}
Fixed Fixed::operator--(int) { // post-décrément
    Fixed tmp(*this);
    --_value;
    return tmp;
}

//MIN AND MAX
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

//COMPARISON
bool Fixed::operator>(const Fixed &other) const { 
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_value != other._value;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}

/*
⣿⣿⡉⠯⠹⠙⠻⠋⠍⠻⣿⣿⢿⣻⣻⠹⣿⡞⣿⣿⣿⣿⣻⢿⣿⡻⣽⢿⢿⡹⣟⡿⣿⢿⣎⡟⢯⡝⢿⢻⡟⣿⡻⡝⠳⣸⢛⠟⣻⡿⣟⡉⠏⣝⣻⣿⣿⡿⠛⢡⠄⠀⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡳⢠⢆⡰⠂⠀⠈⠻⢿⣿⣿⣾⣿⡇⢿⣟⣿⣟⣿⣿⣽⣯⣞⡝⡳⢮⡒⠉⠐⠙⠚⢷⣮⠟⠢⠈⠀⠀⠉⠘⠻⠍⠃⠛⢿⡶⣼⣛⢦⠹⣘⣼⣿⣿⠏⠀⠀⢀⣠⣴⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣷⣝⣾⡁⢀⠠⠀⠠⣤⡘⢿⣿⣿⣧⠸⣧⠹⣿⡾⣿⣿⡽⡻⠄⠉⠃⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠤⡀⠈⠰⠳⢧⣏⠌⠡⣎⣭⣿⠃⠀⣠⡶⠛⠉⠠⢴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡷⢥⠂⡤⠄⣄⡉⢳⣮⠙⣿⣿⡆⢿⡀⢿⣿⣄⣿⣷⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠙⡚⠄⠂⣲⠿⠟⠁⢀⡔⠉⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣝⠢⢀⠀⠀⠈⠙⠷⢶⣆⠈⠿⣿⣿⣷⡾⢿⣿⡀⢿⣃⠈⠀⡀⢆⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⢄⡀⡀⢼⡱⢦⣿⠃⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⣘⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡿⡄⠀⠀⠀⠀⠀⠀⠀⠉⣌⣄⠘⠛⠁⠀⠘⢿⣿⣾⠿⠌⠂⢉⠆⠂⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⡀⠀⠀⠐⠣⠞⠰⠬⠻⠟⠁⠀⠀⠀⣀⣠⣆⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣻⣿⣿⣻⡇⠀⠛⠄⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠿⠀⠀⠀⠠⠘⠀⠀⢀⣠⣤⣿⣿⣿⣿⡿⠿⠿⣿⣧⣤⣤⣄⡀⠀⠀⠀⠀⣀⣤⣿⣿⣿⣿⣿⣄⠀⠀⡀⠀⠠⡜⠃⠘⡛⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿
⣶⣷⣶⣶⣿⣿⡄⠀⠀⠀⠀⠀⠀⠁⣠⣶⣶⣶⣶⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠟⠋⠁⠁⠀⠀⠀⠀⠐⡀⢀⠀⡀⠡⢉⠻⣷⡄⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠄⠐⠀⢾⣷⢾⣶⣶⣿⠾⢿⣿⣿⣿⣿⣿⣿⣿
⠋⠉⠁⠉⠙⢫⣇⠀⢀⡠⠀⠀⢠⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣴⡆⠀⠀⠀⣴⡿⢁⢂⡐⢀⡆⡁⢠⠄⡀⢄⡀⢂⡐⣤⣱⣦⣶⡸⣷⠘⣿⣿⣟⣛⣿⣟⣻⣿⣿⣿⣧⡄⠀⠸⣷⠾⠷⠾⣿⢃⠊⢻⣿⣿⣿⣿⣿⣿
⣿⣿⣶⣾⣿⣿⣿⠂⠀⠀⠀⢠⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⣿⣷⠄⠀⣸⣿⣶⣽⣾⣿⣧⡆⡥⢃⣾⠰⢦⡘⢥⣾⣿⣿⣿⣿⣿⣿⣷⠈⢿⣿⣿⠛⠻⡿⠿⢿⣿⣿⣧⠀⢐⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⢰⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⠏⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⡼⣳⢎⣟⢦⡽⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡐⡀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣼⣿⣿⣿⢿⣯⣽⣿⣦⣿⣿⡙⣿⠃⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣟⣧⣟⣾⣣⢿⣹⣿⣿⣿⣿⣿⡿⠿⠟⠋⠉⠀⠙⢿⣿⣿⣿⣿⣿⣿⣷⣵⡬⠁⠙⠻⡘⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⡷⠀⢠⣿⢛⣿⣿⣾⣿⣿⣿⣿⣿⠿⠃⠀⠀⠀⠈⠿⠿⠿⠿⠿⢿⣿⣿⣿⣿⣷⢾⣿⣯⡿⣽⣿⣿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠨⣏⡉⠉⠉⠛⠉⠉⠁⠀⠀⠠⠤⣘⣦⣛⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡏⠁⠀⢾⣿⠘⣿⣿⣿⠿⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⣍⠓⢦⡀⢒⠒⠲⣀⠁⠲⣄⡓⣞⣳⣮⢿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⠟⡁⢀⠀⠀⠀⠀⠀⠈⢀⢀⡀⠀⠀⠐⠂⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢄⠻⣤⡝⢢⣉⠶⡱⢎⡵⢦⡽⣞⡵⡙⢮⡙⣿⣿⣿⣿⣿
⣿⣿⡿⢱⣊⢹⡡⢎⠰⠌⠛⢠⠂⢁⠂⡁⢀⠤⣦⠁⢊⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⣿⣿⣿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣦⣼⣄⡂⠄⣙⢣⢾⣼⣳⣝⡾⣶⣳⡼⣼⣙⢦⡙⢶⣻⣿⣿⣿
⣿⣿⡳⠳⡜⣫⠕⢮⡱⢉⠶⣀⠡⢊⠰⢀⢠⡣⢠⡑⠠⢀⣠⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⢻⣿⣿⣿⡈⠄⠀⠀⠀⠀⠀⠲⣤⡀⠀⠀⠀⠀⠉⠙⠻⣷⣬⣂⠌⢶⡹⢾⣽⣿⣽⣻⢶⣏⠶⣙⢮⡽⣿⣿⣿
⣿⣿⣳⡹⣜⢧⡻⣭⢳⣮⢳⠜⡬⣁⢆⠱⣊⠁⠀⢉⣾⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠤⡉⢾⣿⣿⣧⡹⣘⠀⠀⠀⠀⠀⠀⠈⠙⠳⣦⣄⡀⠀⠀⠀⠀⠙⠻⢿⣄⠈⠹⣾⡽⡓⢏⠻⣌⠳⢈⠖⡹⢿⣿⣿
⣿⣿⣷⠿⣾⣿⢿⣱⢿⡈⣇⠏⠀⠸⢎⡰⢀⢀⣰⣾⠿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢶⢹⣾⣿⣿⣿⣷⣹⡎⡀⠇⠀⠀⠀⠀⠀⠀⠀⠉⠀⣰⣷⡈⠁⢶⡀⠈⠹⣷⣀⠈⠿⠹⠎⠁⠀⠶⣀⠎⡈⣹⢿⣿
⣿⣿⣭⠟⡻⢞⡽⡞⢧⡹⢌⡖⣨⠗⠀⠀⣰⣿⡟⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡐⢎⡷⣿⣿⣿⣿⣿⣿⣳⣌⠒⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⠶⣿⣦⡀⠈⠙⠛⠿⣶⣦⣄⣠⣀⠀⡀⠀⢁⢫⣟
⣿⣿⣷⠩⠐⠋⠂⢍⢦⣡⢋⡴⠃⠀⠀⣴⡟⠋⠀⠀⠀⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢆⡽⣾⣽⣿⣿⣿⣿⣿⣿⣽⣻⡬⠰⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣶⣤⣄⣀⠀⠀⠉⠁⠉⠂⠁⠒⠠⢀⡩
⣿⣿⣇⠀⠀⠀⡜⣻⢎⢧⢫⠜⠁⠀⡾⠋⠀⠀⣠⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠬⡹⡔⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣗⢣⠒⡠⠀⠀⠀⠀⠀⠉⢺⣷⣦⣞⣦⣄⣀⠀⠙⠻⢶⣄⣀⡀⠠⠖⠖⡠⠀⠀⠀⠀⠀
⣿⣿⣷⣄⡠⣰⡌⠱⢊⠆⡣⢌⠀⠈⠀⠀⣠⣼⠏⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⢀⠈⣐⡧⣽⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣝⣶⡅⡎⢱⡀⠀⠀⠸⣷⣩⠿⢿⣿⡻⢿⣶⣄⠀⠈⠉⠛⠷⣾⣤⠀⠀⠀⠀⠀⠀
⣿⣿⣿⡷⣐⠣⡉⠁⠃⠈⠀⠀⠀⠀⣠⣾⡟⠁⠀⣠⣄⣠⡏⢀⠁⣠⠀⠀⡀⠀⡄⣮⣽⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣣⡎⡍⡜⣡⢿⣿⣜⡌⡹⠿⣦⡀⠙⠷⣄⡈⠛⢶⣄⡉⠉⠀⠀⠀⠀⠀
⣿⣿⣿⡷⣌⠳⡿⠛⠄⠀⠀⠀⠀⢘⣿⠋⢀⣠⣾⡿⢁⣿⠰⡀⢾⡅⢀⠶⣰⣹⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣮⢵⣣⣟⣿⣿⣧⡓⠜⡈⠛⢶⣄⡈⠻⢶⣦⣝⣻⣷⠀⠀⠀⠀⠀
⣿⣿⣿⣿⡧⠉⢂⣁⣤⠖⠀⢀⣤⣾⠿⢾⣿⠟⠁⣐⣎⢯⡣⣝⣿⢎⡜⣮⢳⣿⣿⣿⣿⣿⣿⣿⡿⢿⡹⣟⣿⣷⣋⠟⡜⠳⣻⢟⣿⣿⣿⣿⣿⣿⣯⣿⣾⣽⣿⡿⣽⢘⡐⢦⡀⠙⢻⣦⣄⠙⠻⣿⣿⣿⣤⡀⠀⠀
⣿⣿⣿⣋⣤⣴⡿⠋⠁⣠⣴⠟⠋⠀⣠⡾⠋⢠⣾⠇⣿⣿⢷⣿⣟⣾⣹⣽⣿⣿⣿⣿⣿⡟⣿⢳⢯⢣⠐⡡⠊⠙⢿⣆⠠⢅⡢⡙⢮⡝⣿⣿⣿⣿⣿⣿⣻⣿⣷⢿⣧⢳⡘⢦⣉⠽⣺⠞⣿⣷⣤⡄⣙⠿⣿⣿⣄⠀
⣿⣿⣾⣿⠟⠉⣀⣴⡿⠋⠀⠀⣠⡾⠋⠀⣴⡿⢡⢚⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⢿⡳⢏⠴⢡⠊⡄⠱⢠⡅⠒⣦⡙⣧⡀⠙⢇⠳⡜⢤⣋⠟⣿⣿⣿⣿⣟⡾⣏⡞⣧⣛⢶⣉⠞⣵⣉⠚⠻⢿⣿⣷⣾⣭⣿⣿⡀
⣿⡿⠋⢀⣴⣾⠟⠁⢀⣠⣴⡿⠋⠀⢠⣾⡿⢡⢇⣿⣟⣿⣿⣿⣿⣿⣿⣿⡟⢯⡙⢎⡱⢊⡔⢡⠘⠸⢁⢂⠩⠄⢹⣇⠈⢿⣦⣈⠱⣙⠦⡘⢼⠡⠻⡟⠿⣽⠺⣕⡻⢶⣭⢿⣮⡌⠹⠀⠀⠀⠀⠈⠛⠻⡿⠿⠃⠀
⠋⣠⣾⣿⠟⡡⢂⣶⣿⣿⡟⢡⣼⢧⣾⡟⠄⣑⢾⡟⠈⣿⣿⣿⡿⣿⢿⢏⡙⠂⠜⠠⠑⡆⡜⡡⠂⠀⢌⠢⣈⠃⠘⣿⡀⠀⢿⣿⣧⡈⠣⡌⢄⢊⡱⢌⠰⣠⠻⣼⢹⡻⣞⠿⣿⡆⠀⠀⠀⠀⠀⠀⠀⢀⡷⠀⠀⠀
⣾⣿⣿⡎⣶⣽⣿⣿⣿⣿⣴⣿⡏⣬⠁⡆⢱⠈⣿⠀⠂⠈⠁⠂⢱⠈⡏⠀⠀⠀⠀⠀⠁⢲⢡⠃⡄⠀⠀⢣⠐⡌⠒⡌⢳⠀⠀⢹⣿⣿⡄⠙⣤⠒⣤⠈⢱⡄⡟⣦⡏⣷⢫⣿⣿⠉⠀⠀⠀⠀⠀⠀⠀⠊⠀⠀⠀⠀
⣿⡿⣮⢵⣾⣿⣿⣿⣿⣿⣿⣿⣾⣷⣸⣶⣧⢏⡦⢑⡌⠀⠀⠈⠀⠀⠁⠂⠀⠀⠀⡁⠎⠰⡉⠂⠀⠀⠈⠠⢃⠜⡡⠐⠨⢀⠠⠀⠻⣿⣿⣦⠐⡒⢤⢛⡦⣵⡳⣝⠾⣭⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣿⣝⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⣿⣮⣙⠆⡍⢎⠥⡰⡐⠤⣀⠠⢀⡀⠀⠀⠠⠉⢦⠁⠀⠀⠀⡀⢡⠊⡴⢡⢳⡐⢢⠐⣡⠆⡽⣷⡝⣷⡜⣬⣳⡽⣶⡿⣟⡿⣿⣿⠁⠀⠀⠀⣤⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀
⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⠁⠀⢻⣿⣿⢮⣽⣌⣶⣱⣍⣶⡱⣇⢎⡴⡀⢄⠡⡉⢔⢢⠀⢀⡐⢬⡡⣙⠴⣩⢖⣱⡣⣜⣴⣻⣖⡿⣿⣞⣽⣿⣷⢿⡿⣽⢋⠖⡙⠀⠀⠀⠀⠀⠘⣷⣧⣽⣄⠀⠀⠀⠀⠀⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⢻⣷⣟⢻⡽⣿⢟⣿⣾⣽⣯⣿⣿⣽⣞⣦⣙⢮⡶⣌⣲⢼⣳⡷⣽⣳⣟⣾⣯⣿⣷⣿⣿⣿⣯⢻⣿⣷⡝⣯⡿⡞⠤⠉⠐⠀⠀⠀⠀⠀⠀⠀⠛⠛⠙⠋⠁⠀⠀⠀⠀⠀
⢧⣟⢻⣻⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⢻⣿⡄⢓⠩⠚⡜⢻⠼⣳⣻⢾⡽⣞⣧⢿⣽⣾⣽⣿⣿⣿⢿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡹⢟⣿⣶⠹⡜⣧⡐ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⡷⣎⡳⢮⣝⣻⣿⣟⣿⣿⣿⡟⠀⠀⠀⠀⠀⠈⢻⢿⣾⡐⠣⠌⡀⢃⠱⣫⠟⡽⣙⠞⣯⢻⣟⣿⣿⣿⣿⣻⡿⣽⣻⢿⣿⣻⣟⣿⢯⣟⣯⢿⣷⡘⢼⡘⢧⣝⣲⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/