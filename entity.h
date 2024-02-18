#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "raylib.h"



// Macros
#define MOVEMENT_SPD 150.0f



typedef struct Entity {
    Vector2 position;
    char type;      // 'p' for player, 'e' for enemy, 'i' for inanimate
    int velocity;
    Rectangle hit_box;
} Entity;

int updatePlayer(Entity *player, float delta, GridSquare **grid, int r, int c) {
    if (IsKeyDown(KEY_LEFT)) player->position.x -= MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_UP)) player->position.y -= MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_DOWN)) player->position.y += MOVEMENT_SPD*delta;


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            Rectangle curr_rect = grid[i][j].rect;
            Color curr_rect_color = grid[i][j].color;
            int curr_rect_solid = grid[i][j].solid;

            // If rectangle is solid
            if (curr_rect_solid != 0) {                
                bool hit_obstacle = CheckCollisionRecs(player->hit_box, curr_rect);
                if (hit_obstacle) {
                    player->position = (Vector2) { 5, 5 };
                }
                
            } 

        }
    }
    return 0;
}

Entity spawnEnemy() {

    time_t t;
    srand((unsigned) time(&t));

    int rand_x = 0 + rand() / (RAND_MAX / (600 - 0 + 1) + 1);
    int rand_y = 0 + rand() / (RAND_MAX / (1000 - 0 + 1) + 1);
    
    Entity enemy = {
        (Vector2) { rand_x, rand_y },
        'e',
        0,
        (Rectangle) { rand_x, rand_y, 8, 8 },
    };

    return enemy;

}