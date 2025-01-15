/*******************************************************************************
 * Linked List Implementation in C
 *
 * Author: JORDY OREL KONDA
 * Date: 2025-01-15
 *
 * Description:
 * This program provides a basic implementation of a singly linked list in C.
 * It includes various functionalities such as adding, deleting, searching,
 * sorting, and reversing the linked list. It also provides utility functions
 * like finding the position of a value and printing the list in reverse order.
 *
 * Features:
 * - Encapsulated `List` structure with size tracking.
 * - Node creation and memory management.
 * - Operations: Insert (beginning, end, specific position), delete
 *   (by value, position, first/last), and search.
 * - Additional utilities: Reverse, sort, and recursive printing.
 *
 * License: MIT
 *
 * Usage:
 * Compile with a standard C compiler (e.g., gcc):
 *   gcc -o linked_list linked_list.c
 * Run the compiled program:
 *   ./linked_list
 *
 * Contributions:
 * Contributions and improvements to this code are welcome! Feel free to fork
 * and submit a pull request if you have additional features or optimizations.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct llist {
    Node* head;
    size_t size;
} List;

List* list_head() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Failled to allocate memory.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Add at the begining of the list
void list_push(List* list, int data) {
    if (list == NULL) {
        printf("Error: Linked list is NULL.\n");
        return;
    }

    Node* new_node = create_node(data);
    if (new_node == NULL) {
        printf("Error: Faild to allocate memory for the new node.\n");
        return;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void add_at_end(List* list, int data) {
    if (list == NULL) {
        printf("Error: Linked list is NULL.\n");
        return;
    }

    Node* new_node = create_node(data);
    if (new_node == NULL) {
        printf("Error: Faild to allocate memory for the new node.\n");
        return;
    }
    new_node->next = NULL;

    // If the list is empty, the newNode becomes the first node
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    list->size++;
}

void add_at_key_pos(List* list, int data, int pos) {
    if (list == NULL) {
        printf("The list is empty");
        return;
    }

    Node* new_node = create_node(data);
    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    Node* temp = list->head;
    int count = 0;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of bound. Adding %d at the end.\n", pos,
               data);
        add_at_end(list, data);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    list->size++;
}

void delete_first_node(List* list) {
    if (list->head == NULL) {
        printf("List empty or invalid.\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
}

void delete_last_node(List* list) {
    if (list->head == NULL) {
        printf("List empty or invalid.\n");
        return;
    }

    Node* temp = list->head;
    Node* prev = NULL;

    if (temp->next == NULL) {
        list->head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    list->size--;
}

void delete_node_by_value(List* list, int value) {
    Node* temp = list->head;
    Node* prev = NULL;

    if (temp->data == value) {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    list->size--;
}

void delete_node_at_position(List* list, int position) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head;
    Node* prev = NULL;

    if (position == 0) {
        if (temp == NULL) {
            printf("The list is empty.\n");
            return;
        }
        list->head = temp->next;
        printf("Node at position 0 (value: %d) deleted.\n", temp->data);
        free(temp);
        return;
    }

    int count = 0;
    while (temp != NULL && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d out of bound.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
    list->size--;
}

int get_position_of_value(List* list, int value) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    Node* temp = list->head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    printf("value %d not found in the list.\n", value);
    return -1;
}

void print_position_of_value(List* list, int value) {
    int position = get_position_of_value(list, value);
    if (position != -1) {
        printf("Found %d at position: %d\n", value, position);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

void reverse_list(List* list) {
    if (list == NULL) {
        printf("The list is empty. \n");
        return;
    }

    Node* prev = NULL;
    Node* current = list->head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

void sort_list(List* list) {
    if (list == NULL) {
        printf("The list is empty. \n");
        return;
    }

    Node* prev = list->head;
    while (prev->next != NULL) {
        Node* curr = prev->next;
        while (curr != NULL) {
            if (prev->data > curr->data) {
                int copy = prev->data;
                prev->data = curr->data;
                curr->data = copy;
            }
            curr = curr->next;
        }
        prev = prev->next;
    }
}

size_t list_size(const List* list) { return list ? list->size : 0; }

// Helper function to recursively print nodes
void print_reverse_recursive(Node* node) {
    if (node == NULL) {
        return;
    }
    print_reverse_recursive(node->next);
    printf("%d -> ", node->data);
}

void print_list_reverse(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    print_reverse_recursive(list->head);
    printf("NULL\n");
    printf("List size : %zu\n", list_size(list));
}


void print_list(List* list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("List size : %zu\n", list_size(list));
}

void free_list(List* list) {
    if (list == NULL) {
        return;
    }

    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    List* list = list_head();

    list_push(list, 0);
    list_push(list, 1);
    list_push(list, 2);
    printf("Original list: ");
    print_list(list);

    // sort_list(list);
    // print_list(list);
    // printf("Size after adding elements: %zu\n", list_size(list));

    printf("Revesed list: ");
    print_list_reverse(list);

    // reverse_list(list);
    // printf("Reversed list: ");
    // print_list(list);

    // add_at_end(list, 3);
    // add_at_end(list, 4);
    // printf("After adding 3 and 4 at the end: ");
    // print_list(list);

    // add_at_key_pos(list, 9, 7);
    // print_position_of_value(list, 9);

    delete_node_by_value(list, 1);
    // printf("Size after deleting one element: %zu\n", list_size(list));
    // delete_first_node(list);
    // delete_last_node(list);
    // delete_node_at_position(list, 0);

    free_list(list);

    return 0;
}

// To Do

// Advanced Operations
// Node* merge_sorted_lists(Node* list1, Node* list2);