/* Copyright (c) 2022 Caio Souza, Gustavo Ariadno. All rights reserved. */
/* 42 */

#include <iostream>
#include <bitset>

#include <cmath>
#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    Fixed::rawBits = 0;
}

//std::cout << ": " << std::bitset<8>(fixedPointValue) << std::endl;

Fixed::Fixed(const int fixedPointValue) {
    std::cout << "Int constructor called" << std::endl;
    Fixed::rawBits = fixedPointValue * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float fixedPointValue) {
    std::cout << "Float constructor called" << std::endl;
    //Fixed::rawBits = roundf(fixedPointValue * (1 << Fixed::fractionalBits));
    Fixed::rawBits = fixedPointValue * (1 << Fixed::fractionalBits);
    //Fixed::rawBits = fixedPointValue;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed   &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &rhs)
        return *this;
    this->rawBits = rhs.getRawBits();
    return *this;
}

int     Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (Fixed::rawBits);
}

int     Fixed::getFractionalBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return (Fixed::fractionalBits);
}

void    Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called" << std::endl;
    Fixed::rawBits = raw;
}
    
float   Fixed::toFloat(void) const {
    return 0.0;
}

int     Fixed::toInt(void) const {
    return 0;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &rhs) {
    stream << ((float)rhs.getRawBits() / (1 << rhs.getFractionalBits()));
    return stream;
}
