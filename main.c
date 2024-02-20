// Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


#include "raylib.h"

#include "structdefs.h"

#include "helper_functions/grid.c"
#include "helper_functions/entity.c"

#include "A_Star/astar.c"

#include "maze_creation/maze.c"






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
    const int gridSquareDimension = 100;

     // Set up grid
    int num_rows = height / gridSquareDimension;
    int num_cols = width / gridSquareDimension;
    
    GridNode** grid = NULL;
    grid = createGridMatrix(width, height, gridSquareDimension);

    InitWindow(width, height, "A-Maze-Ing");
    SetTargetFPS(60);


    GridNode start, end;
    start = grid[1][1];
    end = grid[num_rows-2][num_cols-2];
    int AStar_result = AStar(grid, num_rows, num_cols, start, end);


    // Setup entities
    Entity player = { 
        (Vector2) { width/2, height/2 },
        'p',
        0,
    };
    

    // printGridMatrix(grid, num_rows, num_cols);

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
            
        }

        // Drawing objects/entities
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            // Draw grid
            drawGridMatrix(grid, num_rows, num_cols, debug);
           
            // Draw player
            DrawRectangleRec(player.hit_box, BLUE);

            // Start and end squares 
            DrawRectangle(start.grid_square.rect.x, start.grid_square.rect.y, 20, 20, GREEN);
            DrawRectangle(end.grid_square.rect.x, end.grid_square.rect.y, 20, 20, RED);
            

        EndDrawing();
    }


    free(grid);
    CloseWindow();

    return 0;
}