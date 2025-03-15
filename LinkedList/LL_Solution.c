#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);

// Function to check if the linked list is circular
int isCircular(struct Node* head) {
    // If head is null, list is empty, circular
    if (!head) return 1;

    struct Node* temp = head;

    // Traverse until the end is reached or 
    // the next node equals the head
    while (head && head->next != temp)
        head = head->next;

    // If end reached before finding head again,
    // list is not circular
    if (!head || !(head->next))
        return 0;

    // If head found again, list is circular
    return 1;
}

struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Check if the linked list is circular
    isCircular(head) ? printf("Yes\n") : printf("No\n");

    // Making the linked list circular
    head->next->next->next->next = head;

    // Check again if the linked list is circular
    isCircular(head) ? printf("Yes\n") : printf("No\n");
    //BRute force with Time complexity O(n), which is linear
    //Space complexity is O(1)
    return 0;
}
