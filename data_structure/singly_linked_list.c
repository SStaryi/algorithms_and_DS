// singly_linked_list.c

#include "singly_linked_list.h"

const short list_ok_singly = 0;
const short list_not_mem_singly = 1; // Ошибка выделения памяти
const short list_under_singly = 2;
const short list_end_singly = 3;
short list_error_singly = -1;

Node *create_node(base_type data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        // Ошибка выделения памяти
        list_error_singly = list_not_mem_singly;

        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    list_error_singly = list_ok_singly;

    return new_node;
}

void insert_singly(Node **head, base_type data) {
    Node *new_node = create_node(data);

    if (new_node == NULL)
        // Ошибка выделения памяти
        return;

    if (*head == NULL) {
        *head = new_node;

        return;
    }

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

void delete(Node **head, base_type data) {
    if (*head == NULL) {
        // Список пуст
        list_error_singly = list_under_singly;

        return;
    }

    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Элемент не найден в списке
        list_error_singly = list_end_singly;

        return;
    }

    if (previous == NULL)
        // Элемент находится в начале списка
        *head = current->next;
    else
        previous->next = current->next;

    free(current);
}

Node *find(Node *head, base_type data) {
    Node *current = head;

    while (current != NULL && current->data != data)
        current = current->next;

    if (current == NULL) {
        // Элемент не найден в списке
        list_error_singly = list_end_singly;

        return NULL;
    }

    return current;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%lld ", current->data);

        current = current->next;
    }

    printf("\n");
}