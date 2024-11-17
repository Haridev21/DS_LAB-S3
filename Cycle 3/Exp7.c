#include <stdio.h>
#include <stdlib.h>

int Q[25], F = -1, R = -1, MAX = 5;

void insertionAtFront();
void insertionAtRear();
void deletionFromRear();
void deletionFromFront();
void traversal();

int main() {
    int op;
    printf("\n1. InsertionAtRear\n2. InsertionAtFront\n3. DeletionFromRear\n4. DeletionFromFront\n5. Traversal\n6. Exit\n");
    do {
      
        printf("\nEnter the Option: ");
        scanf("%d", &op);
      
        switch(op) {
            case 1: insertionAtRear();
                    break;
            case 2: insertionAtFront();
                    break;
            case 3: deletionFromRear();
                    break;
            case 4: deletionFromFront();
                    break;
            case 5: traversal();
                    break;
            case 6: exit(0);
            default: printf("INVALID INPUT!!\n");
        }
    } while(1);

    return 0;
}

void insertionAtRear() {
    int val;
    if ((R + 1) % MAX == F) {
        printf("Queue overflow at rear\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &val);
        R = (R + 1) % MAX;
        Q[R] = val;
        if (F == -1) {
            F = R;  // Initialize F when first element is inserted
        }
    }
}


void insertionAtFront() {
    int val;
    if ((R + 1) % MAX == F) {
        printf("Queue overflow at front\n");
    } else {
        printf("Enter the element: ");
        scanf("%d", &val);
        if (F == -1) {  
            F = R = 0;
            Q[F] = val;
        } else if (F == 0) {
            F = MAX - 1;  
            Q[F] = val;
        } else {
            F--;  
            Q[F] = val;
        }
    }
}



void deletionFromFront() {
    int val;
    if (F == -1) {
        printf("Queue underflow at front!\n");
    } else {
        val = Q[F];
        printf("The deleted element from front is: %d\n", val);
        if (F == R) {  
            F = R = -1;
        } else {
            F = (F + 1) % MAX;
        }
    }
}


void deletionFromRear() {
    int val;
    if (F == -1) {
        printf("Queue underflow at rear!\n");
    } else {
        val = Q[R];
        printf("The deleted element from rear is: %d\n", val);
        if (F == R) {  
            F = R = -1;
        } else if (R == 0) {
            R = MAX - 1;  
        } else {
            R--;  // Move rear pointer back
        }
    }
}

void traversal() {
    int i;
    if (F == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The elements in the deque are:\n");
        i = F;
        while (i != R) {
            printf("%d ", Q[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", Q[R]);  // Print the last element
    }
}
