#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};
typedef struct node* NODE;


NODE getNode(int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    return temp;
}


NODE insertFront(NODE first, int item) {
    NODE temp = getNode(item);
    if (first == NULL) {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}


NODE insertRear(NODE first, int item) {
    NODE temp = getNode(item);
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}


NODE deleteFront(NODE first) {
    if (first == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    NODE temp = first;
    first = first->rlink;
    if (first != NULL) {
        first->llink = NULL;
    }
    printf("Deleted element: %d\n", temp->info);
    free(temp);
    return first;
}

NODE deleteRear(NODE first) {
    if (first == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    if (cur->llink != NULL) {
        cur->llink->rlink = NULL;
    } else {
        first = NULL;
    }
    printf("Deleted element: %d\n", cur->info);
    free(cur);
    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("List is empty!\n");
        return;
    }
    NODE cur = first;
    printf("List elements: ");
    while (cur != NULL) {
        printf("%d ", cur->info);
        cur = cur->rlink;
    }
    printf("\n");
}


int main() {
    NODE first = NULL;
    int choice, item;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                first = insertFront(first, item);
                break;
            case 2:
                printf("Enter item to insert at rear: ");
                scanf("%d", &item);
                first = insertRear(first, item);
                break;
            case 3:
                first = deleteFront(first);
                break;
            case 4:
                first = deleteRear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
