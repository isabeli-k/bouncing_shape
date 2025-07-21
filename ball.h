#ifndef BALL_H
#define BALL_H

#include "bouncing_shape.h"

typedef struct Ball {
	BouncingShape base;
} Ball;

Ball *Ball_Create (Vector2 position, Vector2 velocity, float radius, Color color);

#endif
