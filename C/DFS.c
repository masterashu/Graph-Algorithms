#include <stdio.h>
#include <stdlib.h>

// Structure for storing adjacent nodes of a vertex
typedef struct AdjacentNodes{
    struct Verticies *data;
    struct AdjacentNodes *next;
}Node;

// Structure for storing verticies of the graph
typedef struct Verticies{
    int data;
    struct Verticies *down;
    int visited;
    Node *next;
}Vertex;

// Cretates and return a node pointer
Node *getNode(Vertex *data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp -> data = data;
    tmp -> next = NULL;
    return tmp;
}

// Creates and return a Vertex pointer
Vertex *getVertex(int data){
    Vertex *tmp = (Vertex*)malloc(sizeof(Vertex));
    tmp -> data = data;
    tmp -> visited = 0;
    tmp -> next = NULL;
    tmp -> down = NULL;
    return tmp;
}

// Inserts a new vertex in the Vertex linked list
Vertex *insertVertex(int data, Vertex *head){
    Vertex *tmp = getVertex(data);
    if(head != NULL){
        tmp -> down = head;
        head = tmp;
    }
    else{
        head = tmp;
    }
    return head;
}

// Utility function to return the desired vertex pointer
Vertex *findVertex(int data, Vertex *head){
    Vertex *tmp = head;
    while(tmp != NULL){
        if(tmp -> data == data)
            return tmp;
        tmp = tmp -> down;
    }
    return NULL;
}

// Insert an undirected edge between two vertex by storing pointers of
// both vertices in the adjacent node list
void insertEdge(int a, int b, Vertex *head){
    
    Vertex *tmp = head, *tmp_a, *tmp_b;
    
    if(head != NULL){
        tmp_a = findVertex(a,head);
        tmp_b = findVertex(b,head);

        // If a and b are present as vertex
        if(tmp_a != NULL && tmp_b !=NULL){
            Node *a_Node = getNode(tmp_a);
            Node *b_Node = getNode(tmp_b);

            a_Node -> next = tmp_b -> next;
            tmp_b -> next = a_Node;

            b_Node -> next = tmp_a -> next;
            tmp_a -> next = b_Node;
        }
        else{
            printf("Vertex not found");
            return;
        }
    }
    else{
        printf("Vertex not found");
        return;
    }
}

// Utility function to make every vertex unvisited
void makeUnVisited(Vertex *head){
    Vertex *tmp = head;
    while(tmp != NULL){
        tmp -> visited = 0;
        tmp = tmp -> down;
    }
}

// A function to print every vertex of graph using DFS(Depth-First-Search)
void DFSprint(Vertex *value){
    if(value != NULL && value->visited != 1){
        printf("%d ",value -> data);
        value->visited++;
        Node *tmp = value -> next;
        while(tmp != NULL){
            DFSprint(tmp -> data);
            tmp = tmp -> next;
        }
    }
}

// Driver hardcoded function 
int main(){
    Vertex *head = NULL;
    head = insertVertex(2,head);
    head = insertVertex(4,head);
    head = insertVertex(1,head);
    head = insertVertex(3,head);
    head = insertVertex(5,head);
    insertEdge(2,4,head);
    insertEdge(1,2,head);
    insertEdge(1,5,head);
    DFSprint(head);
    makeUnVisited(head);
}
