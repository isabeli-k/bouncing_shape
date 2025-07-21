#include "raylib.h"
#include "init_window.h"
#include "square.h"
#include <stdlib.h>

static void Square_Update(void *self, Window *window) {
    Square *square = (Square *)self;
    BouncingShape *s = &square->base;

    s->position.x += s->velocity.x;
    s->position.y += s->velocity.y;

    if ((s->position.x - s->size <= 0) || (s->position.x + s->size >= window->width))
        s->velocity.x *= -1;

    if ((s->position.y - s->size <= 0) || (s->position.y + s->size >= window->height))
        s->velocity.y *= -1;
}

static void Square_Draw(void *self) {
    Square *square = (Square *)self;
    DrawRectangleV(
        (Vector2){square->base.position.x - square->base.size, square->base.position.y - square->base.size},
        (Vector2){square->base.size * 2, square->base.size * 2},
        square->base.color
    );
}

Square *Square_Create(Vector2 position, Vector2 velocity, float radius, Color color) {
    Square *sq = malloc(sizeof(Square));
    sq->base.position = position;
    sq->base.velocity = velocity;
    sq->base.size = radius;
    sq->base.color = color;
    sq->base.update = Square_Update;
    sq->base.draw = Square_Draw;
    return sq;
}
