#include <stdio.h>
#include <stdlib.h>

// Structure to store the adjacent verticies of the graph
typedef struct AdjacentNodes{
    struct Verticies *data;
    struct AdjacentNodes *next;
}Node;

// Structure to store the vertices of the graph
typedef struct Verticies{
    int data;
    struct Verticies *down;
    int enQueued;
    Node *next;
}Vertex;

// Structure to use queue data structure
typedef struct Queue{
     Vertex *data;
    struct Queue *next;
}queue;

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
    tmp -> enQueued = 0;
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
        tmp -> enQueued = 0;
        tmp = tmp -> down;
    }
}

// Utility function to insert into the queue
void enQueue(queue **head, queue **tail, Vertex *data){
    queue *tmp = (queue*)malloc(sizeof(queue));
    tmp -> data = data;
    tmp -> next = NULL;
    data -> enQueued = 1;  
    
    if(*(tail) != NULL){
        (*tail) -> next = tmp;
        (*tail) = tmp;
    }

    if(*tail == NULL){
        (*head) = tmp;
        (*tail) = tmp;
    }
    
}

// Utility function to remove from queue and print
void deQueue(queue **head, queue **tail){
    printf("%d ",(*head)->data->data);
    queue *tmp = (*head);
    if((*head)->next == NULL){
        *head = NULL;
        *tail = NULL;
    }
    else{
        *head = (*head) -> next;
    }
    free(tmp);
}

// Function to print vertices of graph using Breadth First Search
void bfsPrint(queue **head, queue **tail){
    while (*head != NULL)
    {
        Vertex *temp = (*head) -> data;
        Node *iterator = temp -> next;
        while(iterator != NULL){
            if(iterator->data->enQueued == 0){
                enQueue(head, tail, iterator->data);
            }
            iterator = iterator -> next;
        }
        deQueue(head,tail);
    }
}

// Hardcoded driver main
int main(){
    Vertex *root = NULL;
    queue *head = NULL, *tail = NULL;
    root = insertVertex(2,root);
    root = insertVertex(4,root);
    root = insertVertex(1,root);
    root = insertVertex(3,root);
    root = insertVertex(5,root);
    insertEdge(2,4,root);
    insertEdge(1,2,root);
    insertEdge(1,5,root);

    enQueue(&head, &tail, root);
    bfsPrint(&head, &tail);
}
