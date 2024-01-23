#ifndef COMPLEX_COMPLEXNUM_HPP
#define COMPLEX_COMPLEXNUM_HPP
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <concepts>
#include <type_traits>

template <typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template <Arithmetic T>
class ComplexNumber
{
private:
    T real;
    T imaginary;

public:
    ComplexNumber(T real, T imaginary)
        : real(real), imaginary(imaginary)
    {
    }

    T getReal() const
    {
        return real;
    }

    void setReal(T value)
    {
        this->real = value;
    }

    T getImaginary() const
    {
        return imaginary;
    }

    void setImaginary(T value)
    {
        this->imaginary = value;
    }

    ComplexNumber<T> operator+(const ComplexNumber<T>& other) const
    {
        return ComplexNumber<T>(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber<T> operator-(const ComplexNumber<T>& other) const
    {
        return ComplexNumber<T>(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber operator*(const ComplexNumber& other) const
    {
        double newReal = (real * other.real) - (imaginary * other.imaginary);
        double newImaginary = (real * other.imaginary) + (imaginary * other.real);
        return ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber<T> operator/(const ComplexNumber<T>& other) const
    {
        if (other == 0)
        {
            throw std::logic_error("Division by zero.");
        }


        T denominator = (other.real * other.real) + (other.imaginary * other.imaginary);
        T newReal = ((real * other.real) + (imaginary * other.imaginary)) / denominator;
        T newImaginary = ((imaginary * other.real) - (real * other.imaginary)) / denominator;
        return ComplexNumber<T>(newReal, newImaginary);
    }

    bool operator==(const ComplexNumber& other) const
    {
        return std::abs(real - other.real) < std::numeric_limits<double>::epsilon() &&
            std::abs(imaginary - other.imaginary) < std::numeric_limits<double>::epsilon();
    }

    bool operator==(int value) const
    {
        return std::abs(real - value) < std::numeric_limits<double>::epsilon() &&
            std::abs(imaginary) < std::numeric_limits<double>::epsilon();
    }

    bool operator==(double value) const
    {
        return std::abs(real - value) < std::numeric_limits<T>::epsilon() &&
            std::abs(imaginary) < std::numeric_limits<T>::epsilon();
    }

    bool operator!=(const ComplexNumber<T>& other) const
    {
        return !(*this == other);
    }

    bool operator!=(T value) const
    {
        return !(*this == value);
    }

    ComplexNumber<T> operator^(int exponent) const
    {
        T r = std::pow(getModule(), exponent);
        T angle = std::atan2(imaginary, real) * exponent;
        return ComplexNumber<T>(r * std::cos(angle), r * std::sin(angle));
    }

    T getModule() const
    {
        return sqrt((real * real) + (imaginary * imaginary));
    }

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber<T>& complexNumber)
    {
        os << complexNumber.getReal();
        if (complexNumber.getImaginary() >= 0)
        {
            os << " + " << complexNumber.getImaginary() << "i";
        }
        else
        {
            os << " - " << -complexNumber.getImaginary() << "i";
        }
        return os;
    }

    explicit operator int() const
    {
        return static_cast<int>(real);
    }

    explicit operator float() const
    {
        return static_cast<float>(real);
    }

    explicit operator std::string() const
    {
        std::string realStr = std::to_string(real);
        std::string imagStr = std::to_string(abs(imaginary));

        realStr.erase(realStr.find_last_not_of('0') + 1, std::string::npos);
        imagStr.erase(imagStr.find_last_not_of('0') + 1, std::string::npos);

        std::string result = '(' + realStr + (imaginary >= 0 ? " + " : " - ") + imagStr + "i" + ')';

        return result;
    }
};

#endif //COMPLEX_COMPLEXNUM_HPP
