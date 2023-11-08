// queue.c

#include "queue.h"

const short list_ok_queue = 0;
const short list_not_mem_queue = 1; // Ошибка выделения памяти
const short list_under_queue = 2;
short list_error_queue = -1;

Queue *init_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if (queue == NULL) {
        // Ошибка выделения памяти
        list_error_queue = list_not_mem_queue;

        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    list_error_queue = list_ok_queue;

    return queue;
}

void put_queue(Queue *queue, base_type data) {
    Node *new_node = create_node(data);

    if (new_node == NULL)
        // Ошибка выделения памяти
        return;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

base_type get_queue(Queue *queue) {
    if (queue->head == NULL) {
        // Очередь пуста
        list_error_queue = list_under_queue;

        return -1; // Возвращаем -1 или другое значение, которое не может быть в очереди
    }

    Node *temp = queue->head;
    base_type data = temp->data;

    if (queue->head == queue->tail) {
        // В очереди был только один элемент
        queue->head = NULL;
        queue->tail = NULL;
    } else
        queue->head = temp->next;

    free(temp);

    return data;
}

base_type read_queue(Queue *queue) {
    if (queue->head == NULL) {
        // Очередь пуста
        list_error_queue = list_under_queue;

        return -1; // Возвращаем -1 или другое значение, которое не может быть в очереди
    }

    return queue->head->data;
}

bool empty_queue(Queue *queue) {
    return (queue->head == NULL);
}

void done_queue(Queue *queue) {
    Node *current = queue->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(queue);
}