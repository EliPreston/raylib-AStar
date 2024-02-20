// Header files
// #include <stdlib.h>
// #include <stdio.h>
// #include <limits.h>
#include "astarheap.c"




// typedef struct AStarNode {
//     GridNode grid_node;                  // GridNode { int x_center, int y_center, GridSquare grid_square }
//     int f_score;
//     int g_score;
//     int h_score;
//     struct GridNode* previous_node;     // Parent node (for back tracking once a solution has been found)
// } AStarNode;


int AStar(GridNode **grid, int r, int c, GridNode start, GridNode end) {

    AStarNode start_node = {
        start,
        0,
        0,
        0,
        NULL,
    };
    AStarNode end_node = {
        end,
        INT_MAX,
        INT_MAX,
        INT_MAX,
        NULL,
    };

    Heap* open_set = createEmptyHeap(r*c);
    // insertNode(start_node);

    
    free(open_set);
    // free(closed_set);
    return 0;
}









// int main() {

//     GridSquare gs = {
//         10,
//         255,
//         0,
//     };

//     GridNode gn = {
//         100,
//         100,
//         gs,
//     };

//     AStarNode n1 = {gn, 32, 16, 16, NULL};
//     AStarNode n2 = {gn, 43, 13, 30, NULL};
//     AStarNode n3 = {gn, 12, 10, 2, NULL};
//     AStarNode n4 = {gn, 20, 12, 8, NULL};
//     AStarNode n5 = {gn, 13, 5, 8, NULL};

//     AStarNode node_arr[4] = {n1, n2, n3, n4};
//     // n1, n2, n3, n4, n5

//     Heap* node_heap = createHeap(5, node_arr);
//     printf("%d, %d\n", node_heap->capacity, node_heap->size);
//     Heap* empty_node_heap = createEmptyHeap(50);
//     printf("%d, %d\n", empty_node_heap->capacity, empty_node_heap->size);

    
//     insertNode(empty_node_heap, n1);
//     printHeap(empty_node_heap);

//     insertNode(empty_node_heap, n2);
//     printHeap(empty_node_heap);

//     insertNode(empty_node_heap, n3);
//     printHeap(empty_node_heap);

//     insertNode(empty_node_heap, n4);
//     printHeap(empty_node_heap);

//     insertNode(empty_node_heap, n5);
//     printHeap(empty_node_heap);

//     free(empty_node_heap);
//     return 0;
// }