#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *link;
};

struct node *head = NULL;

void traversal();
void insertionatfirst();
void insertionatend();
void insertionatspecific();
void delectionatfirst();
void delectionatspecific();
void delectionatend();

int main() {
    int opt;
    printf("Menu\n");
    printf("1. Traversal\n");
    printf("2. Insertion at First\n");
    printf("3. Insertion at Specific Position\n");
    printf("4. Insertion at End\n");
    printf("5. Deletion at First\n");
    printf("6. Deletion at Specific Position\n");
    printf("7. Deletion at End\n");
    printf("8. Exit\n");

    do {
        printf("\nEnter your option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                traversal();
                break;
            case 2:
                insertionatfirst();
                break;
            case 3:
                insertionatspecific();
                break;
            case 4:
                insertionatend();
                break;
            case 5:
                delectionatfirst();
                break;
            case 6:
                delectionatspecific();
                break;
            case 7:
                delectionatend();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (opt != 8);
    
    return 0;
}

void traversal() {
    struct node *ptr = head;
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void insertionatfirst() {
    int val;
    struct node *ptr;
    printf("\nEnter the data to be inserted: ");
    scanf("%d", &val);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->link = head;
    head = ptr;
}

void insertionatend() {
    int val;
    struct node *ptr, *temp;
    printf("Enter the data to be inserted: ");
    scanf("%d", &val);
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->link = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

void insertionatspecific() {
    int val, pos, i;
    struct node *ptr, *temp;
    printf("Enter the data to be inserted: ");
    scanf("%d", &val);
    printf("Enter the position to insert (1 for first): ");
    scanf("%d", &pos);

    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->link = NULL;

    if (pos == 1) {
        ptr->link = head;
        head = ptr;
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++) {
            temp = temp->link;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
            free(ptr);
        } else {
            ptr->link = temp->link;
            temp->link = ptr;
        }
    }
}


void delectionatfirst() {
    struct node *ptr;
    if (head == NULL) {
        printf("The list is empty!\n");
    } else {
        ptr = head;
        head = head->link;
        printf("The deleted item is %d\n", ptr->data);
        free(ptr);
    }
}

void delectionatend() {
    struct node *pretemp, *temp;
    if (head == NULL) {
        printf("The list is empty\n");
    } else if (head->link == NULL) {
        printf("The deleted item is %d\n", head->data);
        free(head);
        head = NULL;
    } else {
        pretemp = head;
        temp = head->link;
        while (temp->link != NULL) {
            pretemp = temp;
            temp = temp->link;
        }
        pretemp->link = NULL;
        printf("The deleted item is %d\n", temp->data);
        free(temp);
    }
}

void delectionatspecific() {
    int val;
    struct node *pretemp, *temp;
    printf("Enter the value that is to be deleted: ");
    scanf("%d", &val);
    if (head == NULL) {
        printf("The list is empty\n");
    } else if (head->data == val) {
        delectionatfirst();
    } else {
        pretemp = head;
        temp = head->link;
        while (temp != NULL && temp->data != val) {
            pretemp = temp;
            temp = temp->link;
        }
        if (temp == NULL) {
            printf("No node with data %d is present in this list\n", val);
        } else {
            pretemp->link = temp->link;
            printf("The deleted item is %d\n", temp->data);
            free(temp);
        }
    }
}
