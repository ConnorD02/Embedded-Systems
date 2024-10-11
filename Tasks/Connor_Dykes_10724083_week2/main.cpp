#include "mbed.h"
#include <math.h>
#include <iostream>


struct complex {
    double real;
    double i;
    double result;
};

double iAbsolute(struct complex c);
void display(struct complex c);

static void BtoH();

// main() runs in its own thread in the OS
int main()
{
    struct complex Num = {1.0, 1.0};

    Num.result = iAbsolute(Num);

    display(Num);

    BtoH();
}

double iAbsolute(struct complex c)
{
    double a2 = (c.real*c.real) + (c.i*c.i);
    return sqrt(a2);
}

void display(struct complex c)
{
    printf("Absolute value is %f\n",c.result);
}

//static void BtoH(){
//    int bin = 0;
//    int remainder;
//    int hex = 0;
//    int i = 1;
//    printf("Input binary: \n");
//    scanf("%d", &bin);
//    while (bin != 0)
//    {
//        int remainder = bin % 16;
//        int hex = hex + remainder * i;
//        i = i * 2;
//        bin = bin / 16;
//    }
//    printf("Equivalent hexadecimal value: %d %d\n", hex, bin);
//
//}

static void BtoH(){
    std::string input;
    std::cout << "\nInput binary value: ";
    std::cin >> input;
    printf("\nThe hex value of %s is 0x%x", input.c_str(), std::stoi(input,NULL,2));
}