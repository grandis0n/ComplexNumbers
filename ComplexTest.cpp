#include <cassert>
#include "ComplexNum.hpp"

#include <iostream>

constexpr double epsilon = 1e-10;

void test_complex_number_addition()
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber result = z1 + z2;

    assert(result.getReal() == 4.0);
    assert(result.getImaginary() == 6.0);
}

void test_complex_number_subtraction()
{
    ComplexNumber z1(5.0, 8.0);
    ComplexNumber z2(2.0, 3.0);
    ComplexNumber result = z1 - z2;

    assert(result.getReal() == 3.0);
    assert(result.getImaginary() == 5.0);
}

void test_complex_number_multiplication()
{
    ComplexNumber z1(2.0, 3.0);
    ComplexNumber z2(4.0, 5.0);
    ComplexNumber result = z1 * z2;

    assert(result.getReal() == -7.0);
    assert(result.getImaginary() == 22.0);
}

void test_complex_number_division()
{
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(1.0, 2.0);
    ComplexNumber result = z1 / z2;

    assert(result.getReal() == 2.2);
    assert(result.getImaginary() == -0.4);
}

void test_division_by_zero()
{
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(0.0, 0.0);

    try
    {
        ComplexNumber result = z1 / z2;
        assert(false && "Exception not thrown for division by zero.");
    }
    catch (const std::logic_error& e)
    {
        assert(std::string(e.what()) == "Division by zero.");
    }
}


void test_complex_number_equality()
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);
    assert(z1 == z2);
}

void test_complex_number_inequality()
{
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(3.0, 4.0);
    assert(z1 != z2);
    assert(z1 != 3.0f);
}

void test_complex_number_power()
{
    ComplexNumber z(2.0, 3.0);
    ComplexNumber result = z ^ 2.0;

    assert(result.getReal() - (-5.0) < epsilon);
    assert(result.getImaginary() - 12.0 < epsilon);
}

void test_complex_number_module()
{
    ComplexNumber z(3.0, 4.0);
    assert(z.getModule() - 5.0 < epsilon);
}


int main()
{
    test_complex_number_addition();
    test_complex_number_subtraction();
    test_complex_number_multiplication();
    test_complex_number_division();
    test_division_by_zero();
    test_complex_number_equality();
    test_complex_number_inequality();
    test_complex_number_power();
    test_complex_number_module();

    std::cout << "All tests passed" << std::endl;
    return 0;
}
