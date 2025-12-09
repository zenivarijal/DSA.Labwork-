#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if full
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push element
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d\n", value);
}

// Pop element
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int removed = stack->arr[stack->top--];
    printf("Popped %d\n", removed);
    return removed;
}

// Peek top element
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);

    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top element: %d\n", value);
                break;

            case 4:
                if (isEmpty(&stack)) printf("Stack is Empty\n");
                else printf("Stack is NOT Empty\n");
                break;

            case 5:
                if (isFull(&stack)) printf("Stack is Full\n");
                else printf("Stack is NOT Full\n");
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
