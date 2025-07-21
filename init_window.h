#include <stdio.h>

#ifndef INIT_WINDOW_H
#define INIT_WINDOW_H

typedef void (*FuncPtr)(int);

typedef struct Window {
	int width;
	int height;
	const char* title;
	int fullscreen;
} Window;

void Init_Window (Window* window);

#endif
