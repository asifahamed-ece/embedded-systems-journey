#include <stdio.h>

union Color {
    unsigned int rgba;  // Full 32-bit color
    struct {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;  // alpha
    } channels;
};

int main() {
    union Color color;

    // Set full color
    color.rgba = 0xFF5733CC;  // Orange with transparency

    printf("Full Color: 0x%08X\n", color.rgba);
    printf("Red: 0x%02X\n", color.channels.r);
    printf("Green: 0x%02X\n", color.channels.g);
    printf("Blue: 0x%02X\n", color.channels.b);
    printf("Alpha: 0x%02X\n", color.channels.a);

    // Modify individual channel
    color.channels.g = 10;
    printf("\nModified Color: 0x%08X\n", color.rgba);

    return 0;
}
