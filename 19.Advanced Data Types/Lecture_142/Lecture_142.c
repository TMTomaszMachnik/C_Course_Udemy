#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *StackNodePtr;

// Push function
void push(StackNodePtr *top, char data) {
    StackNodePtr temp = malloc(sizeof(node_t));
    if (temp != NULL) {
        temp->data = data;
        temp->nextPtr = *top;
        *top = temp;  // Update the top pointer
    } else {
        printf("Memory allocation failed\n");
    }
}

// Check if stack is empty
int isEmpty(StackNodePtr top) {
    return top == NULL;
}

// Pop function
char pop(StackNodePtr *top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return '\0';  // Return null character for empty stack
    }

    StackNodePtr temp = *top;
    char poppedValue = temp->data;
    *top = (*top)->nextPtr;
    free(temp);
    return poppedValue;
}

// Display stack
void displayStack(StackNodePtr top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (top != NULL) {
        printf("%c -> ", top->data);
        top = top->nextPtr;
    }
    printf("NULL\n");
}

int main() {
    StackNodePtr top = NULL;  // Initialize stack
    int choice;
    char data;
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Push
                printf("Enter a character to push: ");
                scanf(" %c", &data);  // Space before %c to ignore newline
                push(&top, data);
                break;
            case 2:  // Pop
                data = pop(&top);
                if (data != '\0') {
                    printf("Popped: %c\n", data);
                }
                break;
            case 3:  // Display
                displayStack(top);
                break;
            case 4:  // Exit
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
