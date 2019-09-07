#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node_t {
    struct node_t* next_node;
    int value;
} Node;

void mutate_struct(Node* node, int new_val) {
    node->value = new_val;
}

void add_node(Node** head, int value) {
    Node* new_node = malloc(sizeof(Node*));
    new_node->next_node = *head;
    new_node->value = value;
    *head = new_node;
}

void remove_node(Node** head) {
    if (*head == NULL) {
        printf("There are no items to be deleted inside the linked list\n");
    }
    else {
        Node* next_head = (*head)->next_node;
        free(*head);
        *head = next_head;
    }
}

void print_linked_list(Node* current_node) {
    // Head will be the argument parsed
    printf("Head -> ");
    while (current_node != NULL) {
        printf("%d -> ", current_node->value);
        current_node = current_node->next_node;
    }
    printf("NULL\n");
}

bool contains(Node* current_node, int value) {
    // Head will be argument parsed
    while (current_node != NULL) {
        if (current_node->value == value) {
            printf("True\n");
            return true;
        }
        else {
            current_node = current_node->next_node;
        }
    }
    printf("False\n");
    return false;
}

int main() {
    // Testing for linked list
    Node* head = NULL;
    add_node(&head, 8);
    add_node(&head, 10);
    add_node(&head, 12);
    print_linked_list(head);
    contains(head, 12);
    remove_node(&head);
    contains(head, 12);
    remove_node(&head);
    remove_node(&head);
    remove_node(&head);
    remove_node(&head);
    print_linked_list(head);

    return 0;
}