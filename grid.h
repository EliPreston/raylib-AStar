// Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"


typedef struct GridSquare {
    // Rectangle rect = {startx, starty, xdim, ydim};
    Rectangle rect;
    Color color;
    int solid;
    int visited;
} GridSquare;



GridSquare **createGridMatrix(int windowWidth, int windowHeight, int gridSquareDimension) {

    int num_rows = windowHeight / gridSquareDimension;
    int num_cols = windowWidth / gridSquareDimension;
    int num_squares = num_rows * num_cols;
    printf("%d by %d\n", num_rows, num_cols);
    

    GridSquare **grid;
    grid = malloc(num_rows * sizeof(GridSquare *));

    for (int i = 0; i < num_rows; i++) {
        grid[i] = malloc(num_cols * sizeof(GridSquare));
    }

    int x_pos = 0;
    int y_pos = 0;
    
    int solid_val = 0;
    time_t t;
    srand((unsigned) time(&t));

    for (int r = 0; r < num_rows; r++) {
        
        for (int c = 0; c < num_cols; c++) {

            if (rand() % 50 < 15) solid_val = 1;
            
            GridSquare gs = {
                {x_pos, y_pos, gridSquareDimension, gridSquareDimension},
                DARKGRAY,
                solid_val,
                0,
            };

            grid[r][c] = gs;
            x_pos = x_pos + gridSquareDimension;
            solid_val = 0;
        }

        x_pos = 0;
        y_pos = y_pos + gridSquareDimension;
    }
    
    return grid;
}

void printGridMatrix(GridSquare **grid, int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int s = grid[i][j].solid;
            printf("%d ", s);
        }
        printf("\n");
    }
}

int drawGridMatrix(GridSquare **grid, int r, int c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            Rectangle curr_rect = grid[i][j].rect;
            Color curr_rect_color = grid[i][j].color;
            int curr_rect_solid = grid[i][j].solid;

            // If solid != 0
            if (curr_rect_solid) {
                DrawRectangleRec(curr_rect, curr_rect_color); 
            } else {
                // DrawRectangleLinesEx(curr_rect, 1.0, curr_rect_color);
            }

        }
    }

    return 0;
}


