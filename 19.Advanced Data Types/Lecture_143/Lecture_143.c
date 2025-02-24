#include<stdio.h>
#include<malloc.h>
#define MAX 50

struct Qnode {
    int key;
    struct Qnode * next;
};

struct Queue {
    struct Qnode *front, *rear;
};

struct  Qnode * newNode(int k){
    struct Qnode *temp = (struct Qnode *)malloc(sizeof(struct Qnode));
    temp->key = k;
    temp->next = NULL;
    return temp;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q,int k){
    struct Qnode* temp = newNode(k);
    if(q->rear==NULL){
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Qnode* deQueue(struct Queue* q) {
    if(q->front == NULL)
        return NULL;

    struct Qnode* temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;
    return temp;
}

int queue_array[MAX];
int rear = -1;
int front = -1;


int main(){
    int choice;
    struct Queue* q = createQueue();
    enQueue(q,1);
    enQueue(q,2);
    deQueue(q);
    deQueue(q);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    struct  Qnode* n = deQueue(q);
    if( n!= NULL )
        printf("Dequeued item is: %d",n->key);
    return 0;
}