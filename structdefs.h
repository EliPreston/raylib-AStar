// Structs
typedef struct GridSquare {
    Rectangle rect;     // Rectangle rect = {x, y, width, height};
    Color color;
    int solid;
} GridSquare;

typedef struct GridNode {
    int x_center;
    int y_center;
    GridSquare grid_square;
} GridNode;

typedef struct AStarNode {
    GridNode grid_node;                  // GridNode { int x_center, int y_center, GridSquare grid_square }
    int f_score;
    int g_score;
    int h_score;
    struct GridNode* previous_node;     // Parent node (for back tracking once a solution has been found)
} AStarNode;

 
// Heap structure
typedef struct Heap {
    AStarNode* node_arr;
    int size;
    int capacity;
} Heap;
 