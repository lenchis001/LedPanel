#include"Facade.h"

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace LedPanelCore;
#define WIDTH 13
#define HEIGHT 6
#define ACTIVE 5

static int activeCols[ACTIVE];
static int activeRows[ACTIVE];

void init() {
	for (int i = 0; i < ACTIVE; i++) {
		activeRows[i] = -1;
	}
}

void draw() {
	clearAllLeds();

	for (int i = 0; i < ACTIVE; i++)
	{
		if (activeRows[i] >= HEIGHT || activeRows[i] == -1) {

			if (rand() % 3 == 0) {
				activeRows[i] = 0;
				activeCols[i] = rand() % WIDTH;
			}
		}
	}

	for (int i = 0; i < ACTIVE; i++) {
		if (activeCols[i] != -1 && activeRows[i] != -1) {
			if (activeRows[i] < HEIGHT) {
				setLed(activeCols[i], activeRows[i], 100, 100, 255);

				activeRows[i]++;
			}
		}
	}
}

void main() {
	init();

	showWindow(WIDTH, HEIGHT, draw, 50);
}