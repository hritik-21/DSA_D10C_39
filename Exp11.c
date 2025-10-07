#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Global variables
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

// ----- Queue implementation for BFS -----
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

int isQueueEmpty() {
    return (front == -1 || front > rear);
}
// ----- End of Queue implementation -----

// Breadth-First Search function
void bfs(int startVertex) {
    // Initialize queue for BFS
    front = rear = -1;
    
    printf("BFS Traversal: ");

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        // Dequeue a vertex and print it
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// Depth-First Search function (using recursion)
void dfs(int currentVertex) {
    // Mark the current vertex as visited and print it
    visited[currentVertex] = 1;
    printf("%d ", currentVertex);

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < numVertices; i++) {
        if (graph[currentVertex][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

// Function to initialize the visited array before a traversal
void initVisited() {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
}

// Main function to drive the program
int main() {
    int choice, startVertex;

    printf("Enter the number of vertices in the graph (max %d): ", MAX_VERTICES);
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix for the graph (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    while (1) {
        printf("\n--- GRAPH TRAVERSAL MENU ---\n");
        printf("1. Breadth-First Search (BFS)\n");
        printf("2. Depth-First Search (DFS)\n");
        printf("3. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Enter the starting vertex (0 to %d): ", numVertices - 1);
            scanf("%d", &startVertex);

            if (startVertex < 0 || startVertex >= numVertices) {
                printf("Invalid starting vertex!\n");
                continue;
            }
        }

        switch (choice) {
            case 1:
                initVisited(); // Reset visited array
                bfs(startVertex);
                break;
            case 2:
                initVisited(); // Reset visited array
                printf("DFS Traversal: ");
                dfs(startVertex);
                printf("\n");
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}