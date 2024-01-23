#include <cassert>
#include "ComplexNum.hpp"

#include <iostream>

constexpr double epsilon = 1e-10;

template <typename T>
void test_complex_number_addition()
{
    ComplexNumber<T> z1(1.0, 2.0);
    ComplexNumber<T> z2(3.0, 4.0);
    ComplexNumber<T> result = z1 + z2;

    assert(result.getReal() == 4.0);
    assert(result.getImaginary() == 6.0);
}

template <typename T>
void test_complex_number_subtraction()
{
    ComplexNumber<T> z1(5.0, 8.0);
    ComplexNumber<T> z2(2.0, 3.0);
    ComplexNumber<T> result = z1 - z2;

    assert(result.getReal() == 3.0);
    assert(result.getImaginary() == 5.0);
}

template <typename T>
void test_complex_number_multiplication()
{
    ComplexNumber<T> z1(2.0, 3.0);
    ComplexNumber<T> z2(4.0, 5.0);
    ComplexNumber<T> result = z1 * z2;

    assert(result.getReal() == -7.0);
    assert(result.getImaginary() == 22.0);
}

template <typename T>
void test_complex_number_division()
{
    ComplexNumber<T> z1(3.0, 4.0);
    ComplexNumber<T> z2(1.0, 2.0);
    ComplexNumber<T> result = z1 / z2;

    assert(result.getReal() == 2.2);
    assert(result.getImaginary() == -0.4);
}

template <typename T>
void test_division_by_zero()
{
    ComplexNumber<T> z1(3.0, 4.0);
    ComplexNumber<T> z2(0.0, 0.0);

    try
    {
        ComplexNumber<T> result = z1 / z2;
        assert(false && "Exception not thrown for division by zero.");
    }
    catch (const std::logic_error& e)
    {
        assert(std::string(e.what()) == "Division by zero.");
    }
}

template <typename T>
void test_complex_number_equality()
{
    ComplexNumber<T> z1(1.0, 2.0);
    ComplexNumber<T> z2(1.0, 2.0);
    assert(z1 == z2);
}

template <typename T>
void test_complex_number_inequality()
{
    ComplexNumber<T> z1(1.0, 2.0);
    ComplexNumber<T> z2(3.0, 4.0);
    assert(z1 != z2);
    assert(z1 != static_cast<T>(3.0));
}

template <typename T>
void test_complex_number_power()
{
    ComplexNumber<T> z(2.0, 3.0);
    ComplexNumber<T> result = z ^ 2;

    assert(result.getReal() - (-5.0) < epsilon);
    assert(result.getImaginary() - 12.0 < epsilon);
}

template <typename T>
void test_complex_number_module()
{
    ComplexNumber<T> z(3.0, 4.0);
    assert(z.getModule() - 5.0 < epsilon);
}

template <typename T>
void test_cast_to_int()
{
    ComplexNumber<T> z(6.5, 1.7);
    ComplexNumber<T> z1(2.5, -1.7);
    int intValue = int(z);
    int intValue2 = int(z1);
    assert(intValue == 6);
    assert(intValue2 == 2);
}

template <typename T>
void test_cast_to_float()
{
    ComplexNumber<T> z(6.5, 1.7);
    float floatValue = float(z);
    ComplexNumber<T> z1(-3.5, -1.7);
    float floatValue1 = float(z1);
    assert(floatValue - 6.5 < epsilon);
    assert(floatValue1 + 3.5 < epsilon);
}

template <typename T>
void test_cast_to_string()
{
    ComplexNumber<T> z(6.5, 1.7);
    std::string stringValue = std::string(z);
    ComplexNumber<T> z1(6.5, -1.7);
    std::string stringValue1 = std::string(z1);
    assert(stringValue == "(6.5 + 1.7i)");
    assert(stringValue1 == "(6.5 - 1.7i)");
}

int main()
{
    test_complex_number_addition<double>();
    test_complex_number_subtraction<double>();
    test_complex_number_multiplication<double>();
    test_complex_number_division<double>();
    test_division_by_zero<double>();
    test_complex_number_equality<double>();
    test_complex_number_inequality<double>();
    test_complex_number_power<double>();
    test_complex_number_module<double>();
    test_cast_to_int<double>();
    test_cast_to_float<double>();
    test_cast_to_string<double>();
    // static_assert(Arithmetic<std::string>); - ошибка компиляции, т.к string не арифметический
    std::cout << "All tests passed" << std::endl;
    return 0;
}
