#include <iostream>
#include <cmath>
#include <png++/png.hpp>

using namespace std;
using namespace png;

class complex_number {
private:
    double real, imag;

public:
    // Konstruktoren
    complex_number(double r) : real(r), imag(0) {}
    complex_number(double r, double i) : real(r), imag(i) {}

    // Getter für Real- und Imaginärteil
    double get_real() const { return real; }
    double get_imag() const { return imag; }

    // Operatoren
    complex_number& operator+=(const complex_number& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    complex_number& operator-=(const complex_number& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    complex_number& operator*=(const complex_number& other) {
        double temp_real = real * other.real - imag * other.imag;
        imag = real * other.imag + imag * other.real;
        real = temp_real;
        return *this;
    }

    // Freie Funktionen für +, - und *
    friend complex_number operator+(const complex_number& a, const complex_number& b) {
        return complex_number(a.real + b.real, a.imag + b.imag);
    }

    friend complex_number operator-(const complex_number& a, const complex_number& b) {
        return complex_number(a.real - b.real, a.imag - b.imag);
    }

    friend complex_number operator*(const complex_number& a, const complex_number& b) {
        return complex_number(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
    }

    // Ausgabeoperator
    friend ostream& operator<<(ostream& out, const complex_number& c) {
        out << c.real << "+" << c.imag << "i";
        return out;
    }

    // Absolutbetrag
    double abs() const {
        return sqrt(real * real + imag * imag);
    }
};

int main(int argc, char** argv) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <width> <height> <output_filename>" << endl;
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    string output_filename = argv[3];

    image<rgb_pixel> result(width, height);

    const double PI = atan(1.0) * 4;
    const double angle_increment = 0.1;
    const double radius_increment = 0.01;
    complex_number center(width / 2, height / 2);
    complex_number current(0);

    while (current.get_real() >= -width / 2 && current.get_real() < width / 2 && current.get_imag() >= -height / 2 && current.get_imag() < height / 2) {
        // Verschiebe den aktuellen Punkt in die Bildmitte
        complex_number shifted_point = current + center;
        
        // Überprüfe, ob der Pixel innerhalb des gültigen Bereichs des Bildes liegt
        int x = (int)shifted_point.get_real();
        int y = (int)shifted_point.get_imag();
        if (x >= 0 && x < width && y >= 0 && y < height) {
            // Setze den Pixel auf Schwarz
            result[y][x] = rgb_pixel(0, 0, 0);
        }
        
        // Aktualisiere den aktuellen Punkt
        double radius = current.abs();
        double angle = atan2(current.get_imag(), current.get_real());
        radius += radius_increment;
        angle += angle_increment;
        current = complex_number(radius * cos(angle), radius * sin(angle));
    }

    result.write(output_filename);

    return 0;
}
