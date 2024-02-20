// Header files
// #include <stdio.h>
// #include <stdlib.h>
 
 
// Function declarations
Heap* createHeap(int capacity, AStarNode* nodes);
Heap* createEmptyHeap(int capacity);
void heapify(Heap* h, int index);
void insertNode(Heap* h, AStarNode node);
void insertNodeHelper(Heap* h, int index);
AStarNode getMinNode(Heap* h);
 

// Define createHeap function

Heap* createEmptyHeap(int capacity) {

    Heap* h = (Heap*)malloc(sizeof(Heap));

    // Checking if memory is allocated to h or not
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }
    // set the values to size and capacity
    h->size = 0;
    h->capacity = capacity;

    // Allocating memory to array
    h->node_arr = (AStarNode*) malloc(capacity * sizeof(AStarNode));

    // Checking if memory is allocated to h or not
    if (h->node_arr == NULL) {
        printf("Memory error");
        return NULL;
    }

    return h;

}

Heap* createHeap(int capacity, AStarNode* nodes) {
    // Allocating memory to Heap h
    Heap* h = (Heap*)malloc(sizeof(Heap));
 
    // Checking if memory is allocated to h or not
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }
    // set the values to size and capacity
    h->size = 0;
    h->capacity = capacity;
 
    // Allocating memory to array
    h->node_arr = (AStarNode*) malloc(capacity * sizeof(AStarNode));
 
    // Checking if memory is allocated to h or not
    if (h->node_arr == NULL) {
        printf("Memory error");
        return NULL;
    }
    int i;
    for (i = 0; i < capacity; i++) {
        h->node_arr[i] = nodes[i];
    }
 
    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        heapify(h, i);
        i--;
    }
    return h;
}
 
void heapify(Heap* h, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;
 
    // Checking whether our left or child element
    // is at right index or not to avoid index error
    if (left >= h->size || left < 0) left = -1;
    if (right >= h->size || right < 0) right = -1;
 
    // store left or right element in min if
    // any of these is smaller that its parent
    if (left != -1 && h->node_arr[left].f_score < h->node_arr[index].f_score) {
        min = left;
    }
    if (right != -1 && h->node_arr[right].f_score < h->node_arr[min].f_score) {
        min = right;
    }
 
    // Swapping the nodes
    if (min != index) {
        AStarNode temp = h->node_arr[min];
        h->node_arr[min] = h->node_arr[index];
        h->node_arr[index] = temp;
 
        // recursively calling for their child elements
        // to maintain min Heap
        heapify(h, min);
    }
}
 
// Define insertNode function
void insertNode(Heap* h, AStarNode node) {
 
    // Checking if Heap is full or not
    if (h->size < h->capacity) {
        // Inserting node into an array
        h->node_arr[h->size] = node;
        // Calling insertNodeHelper function
        insertNodeHelper(h, h->size);
        // Incrementing size of array
        h->size++;
    }
}

// Defining insertNodeHelper function
void insertNodeHelper(Heap* h, int index) {
 
    // Store parent of element at index
    // in parent variable
    int parent = (index - 1) / 2;
 
    if (h->node_arr[parent].f_score > h->node_arr[index].f_score) {
        // Swapping when child is smaller
        // than parent element
        AStarNode temp = h->node_arr[parent];
        h->node_arr[parent] = h->node_arr[index];
        h->node_arr[index] = temp;
 
        // Recursively calling insertNodeHelper
        insertNodeHelper(h, parent);
    }
}

// Define getMinNode function
AStarNode getMinNode(Heap* h) {
    AStarNode deleteItem;
 
    // Checking if the Heap is empty or not
    if (h->size == 0) {
        printf("\nHeap id empty.");
        NULL;
    }
 
    // Store the node in deleteItem that
    // is to be deleted.
    deleteItem = h->node_arr[0];
 
    // Replace the deleted node with the last node
    h->node_arr[0] = h->node_arr[h->size - 1];
    // Decrement the size of Heap
    h->size--;
 
    // Call minheapify_top_down for 0th index
    // to maintain the Heap property
    heapify(h, 0);
    return deleteItem;
}
 
void printHeap(Heap* h) {
 
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->node_arr[i].f_score);
    }
    printf("\n");
}
 
// int main() {
    
    // int node_arr[] = { 9, 8, 7, -10, 6, 5, 4, 3, 2, 1, -10000 };
    // Heap* hp = createHeap(11, node_arr);
 
    // printHeap(hp);
    // getMinNode(hp);
    // printHeap(hp);
 
    // return 0;
// }