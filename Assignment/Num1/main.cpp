#include <iostream>
#include <cmath>
#include <sstream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0), imaginary(0) {}

    // Constructor with real and imaginary parts
    Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}

    // Constructor from string
    Complex(const std::string& complexString) {
        std::istringstream iss(complexString);
        char discard;
        iss >> discard >> real >> discard >> imaginary >> discard;
    }

    // Getter for real part
    double getReal() const { return real; }

    // Getter for imaginary part
    double getImaginary() const { return imaginary; }

    // Method to calculate magnitude
    double magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Method to calculate angle in radians
    double angle() const {
        return atan2(imaginary, real);
    }

    // Method to calculate complex conjugate
    Complex conjugate() const {
        return Complex(real, -imaginary);
    }

    // Overloaded addition operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overloaded subtraction operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Overloaded multiplication operator
    Complex operator*(const Complex& other) const {
        double resultReal = real * other.real - imaginary * other.imaginary;
        double resultImaginary = real * other.imaginary + imaginary * other.real;
        return Complex(resultReal, resultImaginary);
    }

    // Overloaded division operator
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double resultReal = (real * other.real + imaginary * other.imaginary) / denominator;
        double resultImaginary = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(resultReal, resultImaginary);
    }

    // Method to print complex number
    void Print() const {
        std::cout << "(" << real << ", " << imaginary << ")" << std::endl;
    }
};

int main() {
    // Examples of using the Complex class
    Complex a(1, 2);
    Complex b("3, 4");

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;
    Complex quotient = a / b;

    std::cout << "a + b = ";
    sum.Print();
    std::cout << "a - b = ";
    difference.Print();
    std::cout << "a * b = ";
    product.Print();
    std::cout << "a / b = ";
    quotient.Print();

    return 0;
}
