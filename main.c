// Header files
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "grid.h"
#include "entity.h"




// Program Entry
int main(int argc, char *argv[]) {

    // Initialization ---------------
    time_t t;
    srand((unsigned) time(&t));
    int rand_x;
    int rand_y;

    // Defaults
    const int width = 1000;
    const int height = 600;
    const int gridSquareDimension = 20;

    // If args are passed, rebind them
    // CLA 1: grid square dimension
    // CLA 2: window width
    // CLA 3: window height
    // if (argc == 2) {
    //     int 
    // }
    InitWindow(width, height, "A-Maze-Ing");

    Entity player = { 
        (Vector2) { width/2, height/2 },
        'p',
        0,
    };

    Entity e1 = spawnEnemy();


    // Set up grid
    int num_rows = height / gridSquareDimension;
    int num_cols = width / gridSquareDimension;
    
    GridSquare** grid = NULL;
    grid = createGridMatrix(width, height, gridSquareDimension);
    

    SetTargetFPS(60);

    // Main game loop  ---------------
    while (!WindowShouldClose()) {

        // Updating
        float deltaTime = GetFrameTime();
        player.hit_box = (Rectangle) { player.position.x, player.position.y, 8, 8 };
        
        updatePlayer(&player, deltaTime, grid, num_rows, num_cols);
        
        if (IsKeyPressed(KEY_R)) {
            grid = createGridMatrix(width, height, gridSquareDimension);
            player.position = (Vector2) { width/2, height/2 };

            rand_x = 0 + rand() / (RAND_MAX / (height - 0 + 1) + 1);
            rand_y = 0 + rand() / (RAND_MAX / (width - 0 + 1) + 1);
            e1.position = (Vector2) { rand_x, rand_y };
            e1.hit_box = (Rectangle) { rand_x, rand_y, 8, 8 };
        }


        // Drawing objects/entities
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            // Draw grid
            drawGridMatrix(grid, num_rows, num_cols);
           
            // Draw player
            DrawRectangleRec(player.hit_box, GREEN);
            DrawRectangleRec(e1.hit_box, RED);

        EndDrawing();
    }


    free(grid);
    CloseWindow();

    return 0;
}