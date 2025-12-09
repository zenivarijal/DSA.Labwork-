#include <stdio.h>
#include <stdlib.h> // For exit()

// Define the maximum size of the queue
#define MAX_SIZE 5

// Function prototypes
void enQueue(int);
void deQueue();
void display();

// Global array and pointers
int items[MAX_SIZE], front = -1, rear = -1;

int main() {
  int choice, value;

  printf("? Menu-Driven Queue Implementation (Max Size: %d) ?\n", MAX_SIZE);

  while (1) {
    printf("\n--- Queue Operations ---\n");
    printf("1. Enqueue (Insert element)\n");
    printf("2. Dequeue (Delete element)\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    
    // Check if input is a number
    if (scanf("%d", &choice) != 1) {
        printf("\n?? Invalid input. Please enter a number.\n");
        // Clear the input buffer to prevent infinite loop
        while (getchar() != '\n');
        continue;
    }

    switch (choice) {
      case 1:
        printf("Enter the value to insert: ");
        if (scanf("%d", &value) == 1) {
          enQueue(value);
        } else {
            printf("\n?? Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        }
        break;
      case 2:
        deQueue();
        break;
      case 3:
        display();
        break;
      case 4:
        printf("\nExiting program. Goodbye!\n");
        exit(0);
      default:
        printf("\n?? Invalid choice! Please enter a number between 1 and 4.\n");
    }
  }

  return 0;
}

// --- Function Definitions ---
// Function to add an element to the rear of the queue (Enqueue)
void enQueue(int value) {
  // Check for overflow (Queue is Full)
  if (rear == MAX_SIZE - 1) {
    printf("\nQueue is **Full**! Cannot insert %d.\n", value);
  } else {
    // If the queue was initially empty, set front to 0
    if (front == -1) {
      front = 0;
    }
    // Increment rear and insert the new value
    rear++;
    items[rear] = value;
    printf("\nInserted -> **%d**\n", value);
  }
}

// Function to remove an element from the front of the queue (Dequeue)
void deQueue() {
  // Check for underflow (Queue is Empty)
  if (front == -1 || front > rear) {
    printf("\nQueue is **Empty**! Cannot delete.\n");
  } else {
    // Print the element being deleted
    printf("\nDeleted : **%d**\n", items[front]);
    
    // Move the front pointer forward
    front++;
    
    // If front crosses rear (meaning the last element was deleted), reset front and rear
    if (front > rear) {
      front = rear = -1;
      printf("Queue is now completely empty.\n");
    }
  }
}

// Function to print the elements of the queue
void display() {
  // Check if the queue is empty
  if (rear == -1) {
    printf("\nQueue is **Empty**!!!\n");
  } else {
    int i;
    printf("\nQueue elements are (Front -> Rear):\n");
    
    // Iterate from front to rear and print elements
    for (i = front; i <= rear; i++) {
      printf("%d", items[i]);
      if (i < rear) {
          printf(" <- ");
      }
    }
    printf("\n");
  }
} 



