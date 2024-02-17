// Header files
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "grid.h"



int main(int argc, char *argv[]) {

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


    int num_rows = height / gridSquareDimension;
    int num_cols = width / gridSquareDimension;
    
    GridSquare** grid = NULL;
    grid = createGridMatrix(width, height, gridSquareDimension);
    // printGridMatrix(grid, num_rows, num_cols);
    

    InitWindow(width, height, "A-Maze-Ing");

    while (!WindowShouldClose()) {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            drawGridMatrix(grid, num_rows, num_cols);
            
        EndDrawing();
    }

    free(grid);
    CloseWindow();

    return 0;
}


