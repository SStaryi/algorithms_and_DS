// queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "singly_linked_list.h"

typedef struct Queue {
    Node *head; // Указатель на голову очереди
    Node *tail; // Указатель на хвост очереди
} Queue;

extern const short list_ok_queue;
extern const short list_not_mem_queue; // Ошибка выделения памяти
extern const short list_under_queue;
extern short list_error_queue;

// Создает новую очередь и возвращает указатель на нее.
Queue *init_queue();

// Добавляет элемент в конец очереди.
void put_queue(Queue *queue, base_type data);

// Удаляет элемент из начала очереди и возвращает его.
base_type get_queue(Queue *queue);

// Возвращает элемент из начала очереди без его удаления.
base_type read_queue(Queue *queue);

// Проверяет, пуста ли очередь.
bool empty_queue(Queue *queue);

// Удаляет очередь и освобождает выделенную под нее память.
void done_queue(Queue *queue);

#endif // QUEUE_H