#include "raylib.h"
#include "init_window.h"

void Init_Window (Window* window) {
	if (window->fullscreen) {
		SetConfigFlags(FLAG_FULLSCREEN_MODE);
        InitWindow(0, 0, window->title);
	} else {
		InitWindow(window->width, window->height, window->title);
	}
	
	window->width = GetScreenWidth();
    window->height = GetScreenHeight();
}
