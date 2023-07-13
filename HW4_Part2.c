#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

Node* newNode(int data, int priority) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

void enqueue(Node** head, int data, int priority) {
    Node* temp = newNode(data, priority);

    // If the queue is empty or new node's priority is higher than the head's
    if (*head == NULL || (*head)->priority > priority) {
        temp->next = *head;
        *head = temp;
    } else {
        // Traverse the list and find a position to insert new node
        Node* start = *head;
        while (start->next != NULL && start->next->priority < priority) {
            start = start->next;
        }
        // Either at the ends of the list or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

int dequeue(Node** head) {
    if (isEmpty(head))
        return INT_MIN;
    else {
        Node* temp = *head;
        (*head) = (*head)->next;
        int dequeued = temp->data;
        free(temp);

        return dequeued;
    }
}

void printQueue(Node* head) {
    while(head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    int data, priority, action;
    do {
        printf("Select an action: 1. Enqueue 2. Dequeue, 3. Print 4. Exit\n");
        scanf("%d", &action);

        switch(action) {
            case 1:
                printf("Enter number of nodes: ");
                int count;
                scanf("%d", &count);
                for (int i = 0; i < count; i++) {
                    printf("Enter data and priority for node %d: ", i+1);
                    scanf("%d %d", &data, &priority);
                    enqueue(&head, data, priority);
                }
                break;
            case 2:
                if(isEmpty(&head)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Dequeued %d from the queue\n", dequeue(&head));
                }
                break;
            case 3:
                if(isEmpty(&head)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue: ");
                    printQueue(head);
                }
                break;            
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while(action != 4);

    return 0;
}
