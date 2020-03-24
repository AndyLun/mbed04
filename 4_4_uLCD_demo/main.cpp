#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2);

int main() {
	uLCD.printf("\nHello uLCD World\n");
	uLCD.printf("\n  Starting Demo...");
	uLCD.text_width(4);
	uLCD.text_height(4);
	uLCD.color(RED);

	for(int i = 10; i >= 0; --i) {
		uLCD.locate(1, 2);
		uLCD.printf("%2D", i);
		wait(.5);
	}
}