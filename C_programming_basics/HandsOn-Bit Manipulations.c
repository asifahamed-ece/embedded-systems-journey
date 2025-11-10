/* Hands-On Challenge - LED Control
Your Mission:
Write a program that simulates controlling 8 LEDs using bitwise operations.

Requirements:
Create functions for:

Turn ON a specific LED (set bit)

Turn OFF a specific LED (clear bit)

Toggle a specific LED (flip bit)

Check if LED is ON (read bit)

Display current LED state (show binary) */

#include <stdio.h>
#include <stdint.h>


uint8_t port = 0x00;  //Setting all bits Low in specific Port

void led_on(uint8_t led){
    port |= (1 << led);
    printf("LED%hhu turned ON \n", led);
}

void led_off(uint8_t led){
    port &= ~(1 << led);
    printf("LED%hhu turned OFF \n");
}

void led_toggle(uint8_t led){
    port ^= (1 << led);
    printf("LED%hhu Toggled\n", led);
}

void is_led_on(uint8_t led){
    if(port & (1 << led)){
        printf("LED%hhu is ON\n", led);
    }
    else{
        printf("LED%hhu is OFF\n",led);
    }
}

void display_leds(void){
    printf("--------------------------\n");
    printf("Binary Representation : ");
    for(int i=7; i>=0; i--){
        if(port & (1 << i)){printf("1");}
        else{printf("0");}
    }
    printf("(0x02X)\n", port);

    printf("Display All LED Status\n");
    for(uint8_t i=0; i<8; i++){
        is_led_on(i); //Checking all LED statuses.
    }printf("-------------------------------\n");
}

int main() {
    printf("=== LED Control System ===\n");
    printf("Initial PORT bits : %(0x02X)", port);

    // Test your functions
    display_leds();

    led_on(2);      // Turn ON LED 2
    display_leds();

    led_on(5);      // Turn ON LED 5
    display_leds();

    led_off(2);     // Turn OFF LED 2
    display_leds();

    led_toggle(3);  // Toggle LED 3
    display_leds();

    // Check status
    is_led_on(5);

    return 0;
}
