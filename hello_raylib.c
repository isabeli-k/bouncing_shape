#include "raylib.h"
#include "init_window.h"
#include "bouncing_shape.h"
#include "ball.h"
#include "square.h"
#include <stdlib.h>

#define NUM_OF_SHAPES 2

int main() {
    
    Window window = { .width = 0, 
		.height = 0,
		.title = "OOP-like C",
		.fullscreen = 1,
	};
    
    Ball *ball = Ball_Create((Vector2){400, 300}, (Vector2){20, 15}, 50, RED);
    Square *square = Square_Create((Vector2){600, 400}, (Vector2){-5, 3}, 35, BLUE);
    
    BouncingShape *shapes[NUM_OF_SHAPES] = {
		&ball->base,
		&square->base,
	};
    
    Init_Window(&window);
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
		for (int i = 0; i < NUM_OF_SHAPES; i++) {
			shapes[i]->update(shapes[i], &window);
		}
		
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        for (int i = 0; i < NUM_OF_SHAPES; i++) {
			shapes[i]->draw(shapes[i]);
		}
        
        EndDrawing();
    }
    
    for (int i = 0; i < NUM_OF_SHAPES; i++) {
			free(shapes[i]);
		}
    
    CloseWindow();
    return 0;
}
