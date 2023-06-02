#include "CSphere.h"
#include <cmath>
#include <iostream>

// ����������� �� �������������
CSphere::CSphere() {
    radius = 0.0;
}

// ����������� � �����������
CSphere::CSphere(const CPooint3D& center, double radius) {
    this->center = center;
    this->radius = radius;
}

// ������-����� ��� ��������� �� ��������� ������� ����
void CSphere::setCenter(const CPooint3D& center) {
    this->center = center;
}

void CSphere::setRadius(double radius) {
    this->radius = radius;
}

CPooint3D CSphere::getCenter() const {
    return center;
}

double CSphere::getRadius() const {
    return radius;
}

// ����������� ����� ������� ���
double CSphere::calculateSurfaceArea() const {
    return 4.0 * 3.14 * radius * radius;
}

// ����������� ��'��� ���
double CSphere::calculateVolume() const {
    return (4.0 / 3.0) * 3.14 * radius * radius * radius;
}

// ����������� ��� � ������� �� ����� �������� ���������
void CSphere::translate(double dx, double dy, double dz) {
    double x = center.getX() + dx;
    double y = center.getY() + dy;
    double z = center.getZ() + dz;
    center.setX(x);
    center.setY(y);
    center.setZ(z);
}

// ��������� ������ ��� � ������ ������� ����
void CSphere::increaseRadius(double factor) {
    radius *= factor;
}

void CSphere::consoleInput() {
    double x, y, z;
    std::cout << "Enter the center coordinates of the sphere (x, y, z): ";
    std::cin >> x >> y >> z;
    center.setX(x);
    center.setY(y);
    center.setZ(z);

    bool validInput = false;
    do {
        try {
            std::cout << "Enter the radius of the sphere: ";
            std::cin >> radius;

            if (radius <= 0.0) {
                throw std::runtime_error("Radius must be greater than 0.");
            }

            validInput = true;
        }
        catch (const std::exception& e) {
            std::cout << "Invalid input: " << e.what() << std::endl;
            std::cin.clear();
            //������ �������� ������ �����.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        }
    } while (!validInput);
}

// ���� ����� � �������
void CSphere::consoleOutput() const {
    std::cout << "Center coordinates: (" << center.getX() << "; " << center.getY() << "; " << center.getZ() << ")" << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Surface Area: " << calculateSurfaceArea() << std::endl;
    std::cout << "Volume: " << calculateVolume() << std::endl;
}