#include "mbed.h"

// Define pins
AnalogIn AIN(PC_0);
    // Temperature sensor input (A0)
PwmOut led(LED1);
    // PWM output for LED (choose any pin)

int main() {
        led.period_ms(1.0f);
           // 100 ms polling interval
        float tempread;
           // Variable to store the temperature
        float bright;
           // Variable to store the LED brightness (PWM duty cycle)
    
    while (true) {
        tempread = AIN.read();
        // Step 1: Read the analog input from the temperature sensor
        // Read analog value (0.0 to 1.0)
        float temp = tempread * 100;
        // Step 2: Convert the analog reading to temperature in degrees Celsius
        // Convert to temperature (0°C to 100°C)
        bright = (temp - 20)/20;
        // Step 3: Adjust the brightness of the LED based on the temperature
       if(bright > 1){
           bright = 1;
       }
       if(bright < 0){
           bright = 0;
       }

       // Scale brightness proportionally between 20°C and 40°C
            
        led.write(bright);

        // Step 4: Set the PWM duty cycle to control LED brightness
        // Set LED brightness (0.0 = off, 1.0 = fully on)

        // Step 5: Wait for the polling interval (100 ms)
        wait_us(100000);
    }
}