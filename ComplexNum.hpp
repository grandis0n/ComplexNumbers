#ifndef COMPLEX_COMPLEXNUM_HPP
#define COMPLEX_COMPLEXNUM_HPP

class ComplexNumber
{
private:
    double real;
    double imaginary;

public:
    explicit ComplexNumber(double real = 0.0, double imaginary = 0.0);

    double getReal() const;

    void setReal(double real);

    double getImaginary() const;

    void setImaginary(double imaginary);

    ComplexNumber operator+(const ComplexNumber& other) const;

    ComplexNumber operator-(const ComplexNumber& other) const;

    ComplexNumber operator*(const ComplexNumber& other) const;

    ComplexNumber operator/(const ComplexNumber& other) const;

    bool operator==(const ComplexNumber& other) const;

    bool operator==(int value) const;

    bool operator==(double value) const;

    bool operator!=(const ComplexNumber& other) const;

    bool operator!=(int value) const;

    bool operator!=(float value) const;

    ComplexNumber operator^(int exponent) const;

    double getModule() const;
};


#endif //COMPLEX_COMPLEXNUM_HPP
