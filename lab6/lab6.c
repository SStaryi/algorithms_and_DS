//
// Created by Artyom on 08.11.2023.
//

#include "lab6.h"

Processor *init_processor() {
    Processor *processor = (Processor *) malloc(sizeof(Processor));

    if (processor == NULL)
        // Ошибка выделения памяти
        return NULL;

    processor->task = NULL;
    processor->time_left = 0;

    return processor;
}

void put_processor(Processor *processor, TInquiry *task) {
    processor->task = task;
    processor->time_left = task->Time;
}

TInquiry *get_processor(Processor *processor) {
    TInquiry *task = processor->task;

    processor->task = NULL;
    processor->time_left = 0;

    return task;
}

bool empty_processor(Processor *processor) {
    return (processor->task == NULL);
}

void done_processor(Processor *processor) {
    free(processor);
}

// Основная функция моделирования
void simulate(unsigned N) {
    Queue *F1 = init_queue();
    Queue *F2 = init_queue();
    Queue *F3 = init_queue();
    Stack *S = init_stack();
    Processor *P1 = init_processor();
    Processor *P2 = init_processor();

    // Заполнение очередей F1, F2 и F3 запросами
    TInquiry *task1 = (TInquiry *) malloc(sizeof(TInquiry));
    strcpy(task1->Name, "Task 1");
    task1->Time = 5;
    task1->T = '1';
    put_queue(F1, (base_type) task1);

    TInquiry *task2 = (TInquiry *) malloc(sizeof(TInquiry));
    strcpy(task2->Name, "Task 2");
    task2->Time = 3;
    task2->T = '2';
    put_queue(F2, (base_type) task2);

    TInquiry *task3 = (TInquiry *) malloc(sizeof(TInquiry));
    strcpy(task3->Name, "Task 3");
    task3->Time = 4;
    task3->T = '3';
    put_queue(F3, (base_type) task3);

    for (unsigned t = 0; t <= N; t++) {
        printf("Time: %u\n", t);

        // Обработка запросов
        if (!empty_queue(F1) && empty_processor(P1))
            put_processor(P1, (TInquiry *) get_queue(F1));
        else if (!empty_processor(P1) && P1->task->T == '3' && empty_processor(P2) &&
                 empty_queue(F2)) {
            put_processor(P2, get_processor(P1));

            if (!empty_queue(F1))
                put_processor(P1, (TInquiry *) get_queue(F1));
            else
                put_stack(S, (base_type) get_processor(P1));
        }

        if (!empty_queue(F2) && empty_processor(P2))
            put_processor(P2, (TInquiry *) get_queue(F2));
        else if (!empty_processor(P2) && P2->task->T == '3' && empty_processor(P1) &&
                 empty_queue(F1)) {
            put_processor(P1, get_processor(P2));

            if (!empty_queue(F2))
                put_processor(P2, (TInquiry *) get_queue(F2));
            else
                put_stack(S, (base_type) get_processor(P2));
        }

        if (!empty_queue(F3) && (empty_processor(P1) && empty_queue(F1) ||
                                 empty_processor(P2) && empty_queue(F2))) {
            if (empty_processor(P1) && empty_queue(F1))
                put_processor(P1, (TInquiry *) get_queue(F3));
            else
                put_processor(P2, (TInquiry *) get_queue(F3));
        }

        if (!empty_stack(S) && (empty_processor(P1) && empty_queue(F1) ||
                                empty_processor(P2) && empty_queue(F2))) {
            if (empty_processor(P1) && empty_queue(F1))
                put_processor(P1, (TInquiry *) get_stack(S));
            else
                put_processor(P2, (TInquiry *) get_stack(S));
        }

        if (!empty_processor(P1)) {
            P1->time_left--;

            if (!P1->time_left)
                free(get_processor(P1));
        }

        if (!empty_processor(P2)) {
            P2->time_left--;

            if (!P2->time_left)
                free(get_processor(P2));
        }

        printf("\n");
    }

    done_processor(P1);
    done_processor(P2);
    done_queue(F1);
    done_queue(F2);
    done_queue(F3);
    done_stack(S);
}