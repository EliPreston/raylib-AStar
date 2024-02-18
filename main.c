// Header files
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "helper functions/grid.c"
#include "helper functions/entity.c"
#include "AStar/AStar.c"




// Program Entry
int main(int argc, char *argv[]) {

    // Initialization ---------------
    time_t t;
    srand((unsigned) time(&t));
    int rand_x;
    int rand_y;
    int debug = 0;

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

        if (IsKeyPressed(KEY_G)) {
            switch (debug) {
                case 0: debug = 1; break;
                case 1: debug = 0; break;
            } 
        }
        if (IsKeyPressed(KEY_N)) {
            switch (debug) {
                case 0: debug = 2; break;
                case 2: debug = 0; break;
            } 
        }
        if (IsKeyPressed(KEY_G) && IsKeyPressed(KEY_N)) {
            switch (debug) {
                case 0: debug = 3; break;
                case 3: debug = 0; break;
            } 
        }
        
        if (IsKeyPressed(KEY_R)) {
            grid = createGridMatrix(width, height, gridSquareDimension);
            player.position = (Vector2) { width/2, height/2 };

            rand_x = 0 + rand() / (RAND_MAX / (height - 0 + 1) + 1);
            rand_y = 0 + rand() / (RAND_MAX / (width - 0 + 1) + 1);
            e1.position = (Vector2) { rand_x, rand_y };
            e1.hit_box = (Rectangle) { rand_x, rand_y, 8, 8 };
        }

        int AStar_result = AStar(grid);
        



        // Drawing objects/entities
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            // Draw grid
            drawGridMatrix(grid, num_rows, num_cols, debug);
           
            // Draw player
            DrawRectangleRec(player.hit_box, GREEN);
            DrawRectangleRec(e1.hit_box, RED);

        EndDrawing();
    }


    free(grid);
    CloseWindow();

    return 0;
}