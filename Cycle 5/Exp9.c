#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int number;
    char name[50];
    int totalMarks;
    struct Student* next;
};

struct Student* head = NULL;

void insertAtBeginning(int number, const char* name, int totalMarks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->totalMarks = totalMarks;
    newStudent->next = head;
    head = newStudent;
}

void deleteByNumber(int number) {
    struct Student* temp = head;
    struct Student* prev = NULL;

    if (temp != NULL && temp->number == number) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->number != number) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

struct Student* search(const char* name, int number) {
    struct Student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 || current->number == number) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void sortByNumber() {
    struct Student* current;
    struct Student* next;
    int tempNumber;
    char tempName[50];
    int tempMarks;

    if (head == NULL) return;

    for (current = head; current->next != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (current->number > next->number) {
                tempNumber = current->number;
                current->number = next->number;
                next->number = tempNumber;

                strcpy(tempName, current->name);
                strcpy(current->name, next->name);
                strcpy(next->name, tempName);

                tempMarks = current->totalMarks;
                current->totalMarks = next->totalMarks;
                next->totalMarks = tempMarks;
            }
        }
    }
}

void display() {
    struct Student* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("%-10s %-20s %-10s\n", "Number", "Name", "Total Marks");
    while (current != NULL) {
        printf("%-10d %-20s %-10d\n", current->number, current->name, current->totalMarks);
        current = current->next;
    }
}

int main() {
    int choice, number, totalMarks;
    char name[50];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Sort Students\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student number: ");
                scanf("%d", &number);
                printf("Enter student name: ");
                scanf("%s", name);
                printf("Enter total marks: ");
                scanf("%d", &totalMarks);
                insertAtBeginning(number, name, totalMarks);
                break;
            case 2:
                printf("Enter student number to delete: ");
                if (scanf("%d", &number) != 1) {
                    printf("Invalid input! Please enter a valid number.\n");
                    while (getchar() != '\n');
                    break;
                }
                deleteByNumber(number);
                break;
            case 3:
                printf("Enter student name (or -1 for number search): ");
                scanf("%s", name);
                if (strcmp(name, "-1") == 0) {
                    printf("Enter student number: ");
                    scanf("%d", &number);
                } else {
                    number = -1;
                }
                struct Student* found = search(name, number);
                if (found) {
                    printf("Found: %d, %s, %d\n", found->number, found->name, found->totalMarks);
                } else {
                    printf("Not found\n");
                }
                break;
            case 4:
                sortByNumber();
                printf("Students sorted by number.\n");
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
