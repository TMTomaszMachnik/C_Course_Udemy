#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node{
    char data;
    struct node * nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert( ListNodePtr *head, char value);
void insertAtEnd( ListNodePtr *head, char value);
void insertAtBeginning( ListNodePtr *head, char value);
char delete( ListNodePtr *head, char value);
void insert( ListNodePtr *head, char value);
void deleteAtBeginning( ListNodePtr *head);
void printList( ListNodePtr currentPtr);
int isEmpty( ListNodePtr head);
void insertAtPosition (ListNodePtr *head, char value, int position);
int searchElement (ListNodePtr head, char value);
void updatePosition(ListNodePtr *head, char value, int position);

int main(){
    ListNodePtr head = NULL;
    int choice = 0;
    char item = '\0';
    int position;

    printf("Enter your choice: \n");
    printf("::");
    scanf( "%d", &choice);

    while (choice != 9 ){
        switch (choice)
        {
        case 1:
            printf("Enter a character: ");
            scanf(" \n%c", &item);
            insert(&head, item);
            printList( head );
            break;
        case 2:
            printf("Enter a character: ");
            scanf(" \n%c", &item);
            insertAtEnd(&head, item);
            printList( head );
            break;
        case 3:
            printf("Enter a character: ");
            scanf(" \n%c", &item);
            insertAtBeginning(&head, item);
            printList( head );
            break;
        case 4: //Delete
        if( !isEmpty (head)) {
            printf("Enter a character to be deleted: ");
            scanf(" \n%c", &item);
        
            if ( delete(&head, item)) {
                printf( "%c deleted\n", item);
                printList( head );
            }
            else {
                printf("Element not found");
            }
            break;
        }
        else {
            printf("List is empty\n\n");
        }

        case 5: //Delete at beggining
            if ( !isEmpty( head ) ){
                deleteAtBeginning( &head );
                printf( "%c deleted\n", item);
                printList( head );
            }    
            break;
        case 6:
            printf("Enter a character: ");
            scanf(" %c", &item);
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(&head, item, position);
            printList(head);
            break;
        case 7:
            printf("Enter a character to search: ");
            scanf(" %c", &item);
            int pos = searchElement(head, item);
            if (pos != -1)
                printf("Element %c found at position %d\n", item, pos);
            else
                printf("Element %c not found in the list\n", item);
            break;
        case 8:
            printf("Enter a character: ");
            scanf(" %c", &item);
            printf("Enter the position: ");
            scanf("%d", &position);
            updatePosition(&head, item, position);
            printList(head);
            break;
        default:
            printf("Invalid choice, enter another");
            break;
        }
        scanf("%d", &choice);
    }

    printf("End of run");
    return 0;
}

void insertAtBeginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t)); 
    new_node -> data = value;
    new_node -> nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char value){
    ListNodePtr current = *head;
    if(current != NULL){
        while(current->nextPtr != NULL){
            current = current->nextPtr;
        }
    current->nextPtr = malloc(sizeof(node_t));
    current->nextPtr->data = value;
    current->nextPtr->nextPtr=NULL;
    }
    else{
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
        *head = current;
    }
}

void insert( ListNodePtr *head,char value){
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));
    if( newPtr != NULL ){
        newPtr->data=value;
        newPtr->nextPtr=NULL;
        previousPtr=NULL;
        currentPtr=*head;
        while ( currentPtr != NULL && value > currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
    }   
    if( previousPtr == NULL) {
        newPtr->nextPtr=*head;
        *head=newPtr;
    }
    else{
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
    }
}

void deleteAtBeginning( ListNodePtr *head ) {
    ListNodePtr tempPtr = NULL;
    if (head == NULL) {
        return;
    }
    else{
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free( tempPtr );
    }
}

char delete(ListNodePtr *head, char value){
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if( value == (*head)->data){
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free( tempPtr );
        return value;
    }
    else{
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;
    }
    while( currentPtr != NULL && currentPtr->data != value) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->nextPtr;
    }
    if( currentPtr != NULL ){
        tempPtr = currentPtr;
        previousPtr->nextPtr = currentPtr->nextPtr;
        free( tempPtr );
        return value;
    }
}

void printList( ListNodePtr currentPtr ) {
    if( currentPtr == NULL ){
        printf("List is empty \n");
    }
    else{
        printf("List is: \n");
        while( currentPtr != NULL){
            printf("%c -->", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int isEmpty( ListNodePtr head){
    return head == NULL;
}

void insertAtPosition(ListNodePtr *head, char value, int position) {
    ListNodePtr newPtr = malloc(sizeof(node_t));
    newPtr ->data = value;
    newPtr ->nextPtr = NULL;

    if(position <= 1 || *head == NULL){
        newPtr->nextPtr=*head;
        *head = newPtr;
    }
    else {
        ListNodePtr currentPtr = *head;
        ListNodePtr previousPtr = NULL;
        int count = 1;

        while(currentPtr != NULL && count < position){
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            count++;
        }
        if(previousPtr != NULL) {
            previousPtr->nextPtr=newPtr;
            newPtr->nextPtr= currentPtr;
        }
    }
}

int searchElement (ListNodePtr head, char value){
    int position = 1;
    ListNodePtr searchPtr = head;
    if( head == NULL ){
        printf("Element not found");
    }
    while(searchPtr != NULL) {
        if(searchPtr->data == value){
            return position;
        }
        searchPtr = searchPtr->nextPtr;
        position++;
    }
    return -1;
}

void updatePosition(ListNodePtr *head, char value, int position){
    if ( *head == NULL || position < 1){
        printf("invalid position");
        return;
    }
        ListNodePtr currentPtr = *head;
        int counter = 1;
        while(currentPtr != NULL && counter<position){
            currentPtr= currentPtr->nextPtr;
            counter++;
        }
        if (currentPtr == NULL){
            printf("Element not found\n");
            return;
        }
    currentPtr->data=value;
}