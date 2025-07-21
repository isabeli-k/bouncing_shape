#include "raylib.h"
#include "init_window.h"
#include "ball.h"
#include <stdlib.h>

static void Ball_Update(void *self, Window *window) {
    Ball *ball = (Ball *)self;
    BouncingShape *s = &ball->base;

    s->position.x += s->velocity.x;
    s->position.y += s->velocity.y;

    if ((s->position.x - s->size <= 0) || (s->position.x + s->size >= window->width))
        s->velocity.x *= -1;

    if ((s->position.y - s->size <= 0) || (s->position.y + s->size >= window->height))
        s->velocity.y *= -1;
}

static void Ball_Draw(void *self) {
    Ball *ball = (Ball *)self;
    DrawCircleV(ball->base.position, ball->base.size, ball->base.color);
}

Ball *Ball_Create(Vector2 position, Vector2 velocity, float radius, Color color) {
    Ball *b = malloc(sizeof(Ball));
    b->base.position = position;
    b->base.velocity = velocity;
    b->base.size = radius;
    b->base.color = color;
    b->base.update = Ball_Update;
    b->base.draw = Ball_Draw;
    return b;
}
