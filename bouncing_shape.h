#ifndef BOUNCING_SHAPE_H
#define BOUNCING_SHAPE_H

#include "raylib.h"

typedef struct Window window;

typedef struct BouncingShape {
	Vector2 position;
	Vector2 velocity;
	float size;
	Color color;
	
	void (*update)(void *self, Window *window);
	void (*draw)(void *self);
} BouncingShape;

#endif
