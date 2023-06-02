#ifndef CSPHERE_H
#define CSPHERE_H

#include "CPooint3D.h"

class CSphere {
private:
    CPooint3D center;  
    double radius;    

public:
    // Конструктори
    CSphere();
    CSphere(const CPooint3D& center, double radius);

    // Методи-члени
    void setCenter(const CPooint3D& center);
    void setRadius(double radius);
    CPooint3D getCenter() const;
    double getRadius() const;



    double calculateSurfaceArea() const;
    double calculateVolume() const;
    void translate(double dx, double dy, double dz);
    void increaseRadius(double factor);

    void consoleInput();
    void consoleOutput() const;
};

#endif  
