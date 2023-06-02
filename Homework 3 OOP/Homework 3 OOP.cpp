#include "CSphere.h"
#include <iostream>

    int main() {
        int choice;
        bool exit = false;
        CSphere sphere;

        double surfaceArea;
        double volume;
        double x, y, z;
        double factor;

        while (!exit) {
            std::cout << "| -------------------------" << std::endl;
            std::cout << "| Menu:" << std::endl;
            std::cout << "| 1. Create a new sphere" << std::endl;
            std::cout << "| 2. Calculate surface area" << std::endl;
            std::cout << "| 3. Calculate volume" << std::endl;
            std::cout << "| 4. Move sphere" << std::endl;
            std::cout << "| 5. Increase radius" << std::endl;
            std::cout << "| 6. All informations" << std::endl;
            std::cout << "| 0. Exit" << std::endl;
            std::cout << "| -------------------------" << std::endl;
            std::cout << "  Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1: {
                sphere.consoleInput();
                break;
            }
            case 2: {
                surfaceArea = sphere.calculateSurfaceArea();
                std::cout << "Surface Area: " << surfaceArea << std::endl;
                break;
            }
            case 3: {
                volume = sphere.calculateVolume();
                std::cout << "Volume: " << volume << std::endl;
                break;
            }
            case 4: {
                std::cout << "Enter the coordinates to move the sphere (x, y, z): ";
                std::cin >> x >> y >> z;
                sphere.translate(x, y, z);
                break;
            }
            case 5: {
                std::cout << "Enter the factor to increase the radius: ";
                std::cin >> factor;
                sphere.increaseRadius(factor);
                break;
            }
            case 6: {
                sphere.consoleOutput();
                break;
            }
            case 0: {
                exit = true;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
            }
        }

        return 0;
    }

