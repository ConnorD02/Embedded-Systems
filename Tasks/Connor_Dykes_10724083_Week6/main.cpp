#include "mbed.h"
#include "BufferedSerial.h"

DigitalOut led(LED1); // LED for visual feedback
BufferedSerial pc(USBTX, USBRX); // Serial for debugging output

#define STACK_SIZE 4 // Size of the stack (4 elements)
int stack[STACK_SIZE]; // Stack array
int top = 0; // Stack pointer

void push(int value) {
    if (top >= STACK_SIZE) {
        printf("error stack is full\n");
        // Handle stack full case
    }
    stack[top] = value;				// Push value onto stack and increment top
    top++;
}

int pop() {
    if (top <= 0) {
        printf("error stack is empty\n");
// Handle stack empty case
    }
    top--;				// Decrement top and return the value
    return stack[top];
}

void display_top() {
    if (top <= 0) {
        printf("error stack is empty\n");
// Handle stack empty case
    }
    // Display the top value
    printf("Stack top value = %d\n", stack[top - 1]);
}

int main() {
    push(1);				// Push first value
    push(2);				// Push second value


    display_top(); 	// Display top value after pushing

    pop();				// Pop the top value
    display_top(); 	// Display new top value after popping

    while (1) {
        led = !led; // Blink LED
        wait_us(500000); // Wait half a second
    }
}
