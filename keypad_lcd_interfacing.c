#include <reg51.h>

sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;

unsigned char key[] = "123456789*0#";
unsigned char cmmd[] = {0x38, 0x0E, 0x06, 0x80};

void delay() {
    unsigned int x;
    for (x = 0; x < 3000; x++);
}

void lcd_cmd(unsigned char cmd) {
    P1 = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void lcd_data(unsigned char dat) {
    P1 = dat;
    rs = 1;
    rw = 0;
    en = 1;
    delay();
    en = 0;
}

void lcd_init() {
    unsigned char i;
    for (i = 0; i < 4; i++) {
        lcd_cmd(cmmd[i]);
        delay();
    }
}

void main() {
    unsigned char row, col, keynum;

    lcd_init();

    while (1) {
        P2 = 0xF0; // Make rows high and columns low
        if ((P2 & 0xF0) != 0xF0) { // If any key is pressed
            delay(); // Debounce delay
            for (row = 0; row < 4; row++) {
                P2 = ~(1 << row); // Send low to one row at a time
                for (col = 0; col < 3; col++) {
                    if (!(P2 & (0x10 << col))) { // Check column
                        keynum = row * 3 + col;
                        lcd_data(key[keynum]);
                        delay();
                        while (!(P2 & (0x10 << col))); // Wait for release
                    }
                }
            }
        }
    }
}
