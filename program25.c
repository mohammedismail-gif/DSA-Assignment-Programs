#include <stdio.h>
#include <stdlib.h>

/* Structure for adjacency list node */
struct adjNode {
    int dest;
    struct adjNode* next;
};

/* Graph structure */
struct Graph {
    int V;
    struct adjNode** array;
};

/* Create new adjacency node */
struct adjNode* newAdjNode(int dest) {
    struct adjNode* newNode = (struct adjNode*)malloc(sizeof(struct adjNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

/* Create graph with V vertices */
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct adjNode**)malloc(V * sizeof(struct adjNode*));
    for(int i=0;i<V;i++) graph->array[i] = NULL;
    return graph;
}

/* Add edge */
void addEdge(struct Graph* graph, int src, int dest) {
    struct adjNode* newNode = newAdjNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    /* For undirected graph, add edge from dest to src */
    newNode = newAdjNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

/* Stack for DFS */
struct Stack {
    int items[100];
    int top;
};

void push(struct Stack* s, int val) { s->items[++(s->top)] = val; }
int pop(struct Stack* s) { return s->items[(s->top)--]; }
int isEmptyStack(struct Stack* s) { return s->top == -1; }

/* Queue for BFS */
struct Queue {
    int items[100];
    int front, rear;
};

void enqueue(struct Queue* q, int val) { q->items[++(q->rear)] = val; }
int dequeue(struct Queue* q) { return q->items[(q->front)++]; }
int isEmptyQueue(struct Queue* q) { return q->front > q->rear; }

/* DFS using stack */
void DFS(struct Graph* graph, int start) {
    int V = graph->V;
    int visited[V];
    for(int i=0;i<V;i++) visited[i]=0;

    struct Stack s;
    s.top = -1;
    push(&s, start);

    printf("DFS Traversal: ");
    while(!isEmptyStack(&s)) {
        int v = pop(&s);
        if(!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
        }

        struct adjNode* temp = graph->array[v];
        while(temp) {
            if(!visited[temp->dest]) push(&s, temp->dest);
            temp = temp->next;
        }
    }
    printf("\n");
}

/* BFS using queue */
void BFS(struct Graph* graph, int start) {
    int V = graph->V;
    int visited[V];
    for(int i=0;i<V;i++) visited[i]=0;

    struct Queue q;
    q.front=0; q.rear=-1;
    enqueue(&q, start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while(!isEmptyQueue(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);

        struct adjNode* temp = graph->array[v];
        while(temp) {
            if(!visited[temp->dest]) {
                enqueue(&q, temp->dest);
                visited[temp->dest] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int V, E, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);

    printf("Enter edges (src dest):\n");
    for(int i=0;i<E;i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    DFS(graph, 0);  // DFS starting from vertex 0
    BFS(graph, 0);  // BFS starting from vertex 0
    system("getmac");
    return 0;
}
