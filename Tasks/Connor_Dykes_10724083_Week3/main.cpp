#include "mbed.h"
#include <cstring>

//Initialise class and parameters
class rectangle {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    rectangle(double l, double w) {
        this->length = l;
        this->width = w;
    }

    // Function to get the area of the rectangle
    double area() {
        double a = this->length * this->width;
        return a;
    }

    // Function to get the perimeter of the rectangle
    double perimeter() {
        double p = (this->length + this->width)*2;
        return p;
    }
};

int main() {
    // Start serial communication
    printf("Program Starting...\n");

    // Create a rectangle object
    rectangle rectangle1(10, 5);

    //Outputs the calcualted area and perimeter of the rectangle
    printf("Rectangle area: %f\n", rectangle1.area());
    printf("Rectangle perimeter: %f\n", rectangle1.perimeter());

    return 0;
}
