#include "LCD.h"

DigitalOut RS(D2);
DigitalOut E(D3);
BusOut dat(D4, D5, D6, D7);

void toggle_enable(void) {
	E = 1;
	wait(0.001);
	E = 0;
	wait(0.001);
}

void LCD_init(void) {
	wait(0.02);
	RS = 0;
	E = 0;

	// Function mode
	dat = 0x2;
	toggle_enable();
	dat = 0x8;
	toggle_enable();

	// Display mode
	dat = 0x0;
	toggle_enable();
	dat = 0xF;
	toggle_enable();

	// Clear display
	dat = 0x0;
	toggle_enable();
	dat = 0x1;
	toggle_enable();
}

void display_to_LCD(char value) {
	RS = 1;
	dat = value >> 4;
	toggle_enable();
	dat = value;
	toggle_enable();
}

void set_location(char location) {
	RS = 0;
	dat = (location | 0x80) >> 4;
	toggle_enable();
	dat = location & 0x0F;
	toggle_enable();
}