#include "mbed.h"
#include <cstring>

class rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    rectangle(double l, double w) {
        length = l;
        width = w;
    }

    // Function to get the area of the rectangle
    double area() {
        double a = length * width;
        return a;
    }

    // Function to get the perimeter of the rectangle
    double perimeter() {
        double p = (2*length) + (2*width);
        return p;
    }
};
//The main function - all executable C / C++ applications have a main function. This is our entry point in the software
int main() {
    // Start serial communication
    printf("Program Starting...\n");

    // Create a Student object
    rectangle rectangle1(10, 5);

    // Output the name and age of the student
    printf("Rectangle area: %f\n", rectangle1.area());
    printf("Rectangle perimeter: %f\n", rectangle1.perimeter());

    return 0;
}
