// Header files -- included in main
// #include <stdio.h> 
// #include <stdlib.h>
// #include <time.h>



GridNode **createGridMatrix(int windowWidth, int windowHeight, int gridSquareDimension) {

    int num_rows = windowHeight / gridSquareDimension;
    int num_cols = windowWidth / gridSquareDimension;
    int num_squares = num_rows * num_cols;

    GridNode **grid;
    grid = malloc(num_rows * sizeof(GridNode *));

    for (int i = 0; i < num_rows; i++) {
        grid[i] = malloc(num_cols * sizeof(GridNode));
    }

    int x_pos = 0;
    int y_pos = 0;
    int x_center;
    int y_center;
    
    int solid_val = 0;
    time_t t;
    srand((unsigned) time(&t));

    for (int r = 0; r < num_rows; r++) {
        
        for (int c = 0; c < num_cols; c++) {


            x_center = x_pos + (gridSquareDimension/2);
            y_center = y_pos + (gridSquareDimension/2);
        
            // if (rand() % 50 <10) solid_val = 1;
            if (r == 0) solid_val = 1;
            if (c == 0) solid_val = 1;
            if (r == num_rows-1) solid_val = 1;
            if (c == num_cols-1) solid_val = 1;
            
            GridSquare gs = {
                {x_pos, y_pos, gridSquareDimension, gridSquareDimension},
                DARKGRAY,
                solid_val,
            };

            GridNode gn = {
                x_center,
                y_center,
                gs,
            };

            grid[r][c] = gn;
            x_pos = x_pos + gridSquareDimension;
            solid_val = 0;
        }

        x_pos = 0;
        y_pos = y_pos + gridSquareDimension;
    }

    // printGridMatrix(grid, num_rows, num_cols);
    // printf("%d by %d\n", num_rows, num_cols);
    
    return grid;
}

void printGridMatrix(GridNode **grid, int r, int c) {


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int s = grid[i][j].grid_square.solid;
            printf("%d ", s);
        }
        printf("\n");
    }
    printf("%d by %d\n", r, c);
    return;
}

int drawGridMatrix(GridNode **grid, int r, int c, int debug) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            Rectangle curr_rect = grid[i][j].grid_square.rect;
            Color curr_rect_color = grid[i][j].grid_square.color;
            int curr_rect_solid = grid[i][j].grid_square.solid;
            GridNode curr_node = grid[i][j];

            // If solid != 0
            if (curr_rect_solid) {
                DrawRectangleRec(curr_rect, curr_rect_color); 
            } else if (debug == 1) {
                DrawRectangleLinesEx(curr_rect, 0.25, curr_rect_color);
            } else if (debug == 2) {
                DrawCircle(curr_node.x_center, curr_node.y_center, 1, RED);
            } else if (debug == 3) {
                DrawRectangleLinesEx(curr_rect, 0.25, curr_rect_color);
                DrawCircle(curr_node.x_center, curr_node.y_center, 1, RED);
            }
            
            // DrawCircle(curr_node.x_center, curr_node.y_center, 1, RED);

        }
    }

    return 0;
}