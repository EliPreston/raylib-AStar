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

int updatePlayer(Entity *player, float delta, GridNode **grid, int r, int c) {
    if (IsKeyDown(KEY_LEFT)) player->position.x -= MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_RIGHT)) player->position.x += MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_UP)) player->position.y -= MOVEMENT_SPD*delta;
    if (IsKeyDown(KEY_DOWN)) player->position.y += MOVEMENT_SPD*delta;


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            Rectangle curr_rect = grid[i][j].grid_square.rect;
            Color curr_rect_color = grid[i][j].grid_square.color;
            int curr_rect_solid = grid[i][j].grid_square.solid;

            bool hit_obstacle = false;
            int reset_x = 5;
            int reset_y = 5;

            // If rectangle is solid
            if (curr_rect_solid != 0) {                
                hit_obstacle = CheckCollisionRecs(player->hit_box, curr_rect);
                if (hit_obstacle) {
                    
                    // if (curr_rect.x < player->position.x) {
                    //     reset_x = player->position.x - 5;
                    // } else if (curr_rect.x > player->position.x) {
                    //     reset_x = player->position.x + 5;
                    // }

                    // if (curr_rect.y < player->position.y) {
                    //     reset_y = player->position.y - 5;
                    // } else if (curr_rect.y > player->position.y) {
                    //     reset_y = player->position.y + 5;
                    // }

                    player->position = (Vector2) { reset_x, reset_y };

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