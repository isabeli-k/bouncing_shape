#ifndef SQUARE_H
#define SQUARE_H

#include "bouncing_shape.h"

typedef struct Square {
	BouncingShape base;
} Square;

Square *Square_Create (Vector2 position, Vector2 velocity, float radius, Color color);

#endif
