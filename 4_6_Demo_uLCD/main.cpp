#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);

int main() {
	uLCD.text_width(4);
	uLCD.text_height(4);
	uLCD.background_color(WHITE);
	uLCD.cls();

	uLCD.color(BLUE);
	uLCD.locate(1, 1);
	uLCD.printf("ID: 107000270\n");

	uLCD.color(GREEN);
	int x = 30;
	while(x > 0) {
		uLCD.locate(1, 2);
		uLCD.printf("%2D", x);
		wait(1);
		x--;
	}
}