
#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct llist {
    Node* head;
} List;

List* list_head() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

Node* create_node() {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Failled to allocate memory.\n");
        return NULL;
    }
    new_node->data = 0;
    new_node->next = NULL;
    return new_node;
}

// Add at the begining of the list
void list_push(List* list, int data) {
    if (list == NULL) {
        printf("Error: Linked list is NULL.\n");
        return;
    }

    Node* new_node = create_node();
    if (new_node == NULL) {
        printf("Error: Faild to allocate memory for the new node.\n");
        return;
    }
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void add_at_end(List* list, int data) {
    if (list == NULL) {
        printf("Error: Linked list is NULL.\n");
        return;
    }

    Node* new_node = create_node();
    if (new_node == NULL) {
        printf("Error: Faild to allocate memory for the new node.\n");
        return;
    }
    new_node->data = data;
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
}

void add_at_key_pos(List* list, int data, int pos) {
    if (list == NULL) {
        printf("The list is empty");
        return;
    }
    
    Node* new_node = create_node();
    new_node->data = data;

    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }
    
    Node* temp = list->head;
    int count = 0;
    while (temp!= NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position %d is out of bound. Adding %d at the end.\n",pos, data);
        add_at_end(list, data);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_first_node(List* list) {
    if (list->head == NULL) {
        printf("List empty or invalid.\n");
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
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

}

/**
 * Deletes the node at the specified position in the list.
 *
 * @param list The linked list.
 * @param position The 0-based index of the node to delete.
 *
 * Note: Position 0 refers to the first node in the list.
 *       Position 1 refers to the second node, and so on.
 *
 * Example:
 * For a list: 10 -> 20 -> 30 -> NULL
 * delete_node_at_position(list, 0) deletes 10 (the first node).
 * delete_node_at_position(list, 1) deletes 20 (the second node).
 */
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

}

int get_position_of_value(List* list, int value) {
    if (list == NULL || list->head == NULL) {
        printf("The list is empty.\n");
        return -1;
    }

    Node* temp = list->head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value){
            return position;
        } 
        temp = temp->next;
        position ++;
    }

    printf("value %d not found in the list.\n", value);
    return -1;
}

void reverse_list(Node** head) {
    if (head == NULL) {
        printf("The list is empty. \n");
        return;
    }

    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;

    }
    head = &prev;
}

void print_position_of_value(List* list, int value) {
    int position = get_position_of_value(list, value);
    if (position != -1) {
        printf("Found %d at position: %d\n", value, position);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
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
}

int main() {
    List* list = list_head();

    list_push(list, 2);
    list_push(list, 1);
    list_push(list, 0);
    printf("Original list: ");
    print_list(list);

    reverse_list(&(list->head));
    printf("Reversed list: ");
    print_list(list);

    // add_at_end(list, 3);
    // add_at_end(list, 4);
    // printf("After adding 3 and 4 at the end: ");
    // print_list(list);

    // add_at_key_pos(list, 9, 7);
    // print_position_of_value(list, 9);

   

    // delete_node_by_value(list, 1);
    // delete_first_node(list);
    // delete_last_node(list);
    // delete_node_at_position(list, 0);

    free_list(list);


    return 0;
}

// To Do

// Insert Operations 
// void insert_after_value(Node* head, int target, int data);


// // Traversal Operations
// void print_list_reverse(Node* head);
// int count_nodes(Node* head);

// Advanced Operations
//  
//void sort_list(Node** head);
// Node* merge_sorted_lists(Node* list1, Node* list2);

// Utility Functions
// void free_list(Node** head) 
// int is_empty(Node* head)