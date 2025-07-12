# 8051 LCD + 4x3 Keypad Interfacing 

This project demonstrates how to interface a **4x3 matrix keypad** with a **16x2 LCD** using an **8051 microcontroller (AT89C51/AT89S52)**. When a key is pressed on the keypad, the corresponding character is detected and displayed in real-time on the LCD screen.

## What You'll Need

- **AT89C51 / AT89S52 Microcontroller**
- **16x2 LCD** (HD44780-compatible)
- **4x3 Matrix Keypad**
- **10kΩ Potentiometer** (for contrast)
- **Crystal oscillator (11.0592 MHz)** + Capacitors
- **Breadboard + Jumper Wires**
- **+5V Regulated Power Supply**
  
## Pin Configuration

### LCD Connections

| LCD Pin | Function     | 8051 Pin        |
|---------|--------------|-----------------|
| RS      | Register Select | P0.0         |
| RW      | Read/Write      | P0.1         |
| EN      | Enable           | P0.2        |
| D0–D7   | Data Pins        | P1.0 – P1.7  |

### Keypad Connections

| Keypad Line | Connected To |
|-------------|--------------|
| R0 – R3     | P2.0 – P2.3  |
| C0 – C2     | P2.4 – P2.6  |

## How It Works

- The **LCD** is initialized in **8-bit mode**, with cursor ON.
- The **keypad** is scanned by:
  1. Driving one **row LOW** at a time.
  2. Reading **columns** to detect which key is pressed.
  3. Using `row * 3 + col` to find the character.
- The pressed key is **instantly displayed** on the LCD.

## Keypad Layout
Mapped in code as:

unsigned char key[] = {
  '1','2','3',
  '4','5','6',
  '7','8','9',
  '*','0','#'
};

## Files in this repo
1. Source Code: keypad_lcd_interfacing.c (written in Kevin uVision5)
2. Proteus File: keypad_interfacing_8051.pdsprj (Proteus 8 Professional)
3. Video simulation: keypadd_LCD_interfacing_8051.mp4

## Future Ideas
-Use * as clear, # as enter
-Display full numbers instead of single chars
-Add serial output (UART) of entered key
-Enable password-type functionality

## References
-8051 Datasheet – AT89S52
-HD44780 LCD Datasheet
-Matrix Keypad Theory
-Embedded C and Keil IDE basics

## Author
**Anwesha Rath**  
Electrical Engineering  
_GitHub: [@123739](https://github.com/123739)_

If you found this useful, give the repo a ⭐️ and consider contributing improvements or variations!
