#include <limits>
#include "ComplexNum.hpp"

#include <iostream>
#include <cmath>

ComplexNumber::ComplexNumber(double real, double imag) : real(real), imaginary(imag)
{
}

double ComplexNumber::getReal() const
{
    return real;
}

void ComplexNumber::setReal(double value)
{
    this->real = value;
}

double ComplexNumber::getImaginary() const
{
    return imaginary;
}

void ComplexNumber::setImaginary(double value)
{
    this->imaginary = value;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    return ComplexNumber(real + other.real, imaginary + other.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    return ComplexNumber(real - other.real, imaginary - other.imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    double newReal = (real * other.real) - (imaginary * other.imaginary);
    double newImaginary = (real * other.imaginary) + (imaginary * other.real);
    return ComplexNumber(newReal, newImaginary);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const
{
    if (other == 0)
    {
        throw std::logic_error("Division by zero.");
    }


    double denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
    double newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
    double newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
    return ComplexNumber(newReal, newImaginary);
}

bool ComplexNumber::operator==(const ComplexNumber& other) const
{
    return std::abs(real - other.real) < std::numeric_limits<double>::epsilon() &&
        std::abs(imaginary - other.imaginary) < std::numeric_limits<double>::epsilon();
}

bool ComplexNumber::operator==(int value) const
{
    return std::abs(real - value) < std::numeric_limits<double>::epsilon() &&
        std::abs(imaginary) < std::numeric_limits<double>::epsilon();
}

bool ComplexNumber::operator==(double value) const
{
    return std::abs(real - value) < std::numeric_limits<double>::epsilon() &&
        std::abs(imaginary) < std::numeric_limits<double>::epsilon();
}

bool ComplexNumber::operator!=(const ComplexNumber& other) const
{
    return !(*this == other);
}

bool ComplexNumber::operator!=(int value) const
{
    return !(*this == value);
}

bool ComplexNumber::operator!=(float value) const
{
    return !(*this == value);
}

double ComplexNumber::getModule() const
{
    return sqrt((real * real) + (imaginary * imaginary));
}


ComplexNumber ComplexNumber::operator^(int exponent) const
{
    double r = std::pow(getModule(), exponent);
    double angle = std::atan2(imaginary, real) * exponent;
    return ComplexNumber(r * std::cos(angle), r * std::sin(angle));
}


std::ostream& operator<<(std::ostream& os, const ComplexNumber& complexNumber)
{
    os << complexNumber.getReal() << " + " << complexNumber.getImaginary() << "i";
    return os;
}
