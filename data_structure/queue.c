// queue.c

#include "queue.h"

const short queue_ok = 0;
const short queue_not_mem = 1; // Ошибка выделения памяти
const short queue_under = 2;
short queue_error = -1;

Queue *init_queue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));

    if (queue == NULL) {
        // Ошибка выделения памяти
        queue_error = queue_not_mem;

        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue_error = queue_ok;

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
        queue_error = queue_under;

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
        queue_error = queue_under;

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