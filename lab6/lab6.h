//
// Created by Artyom on 08.11.2023.
//

#ifndef ALGORITMS_AND_DS_LAB6_H
#define ALGORITMS_AND_DS_LAB6_H

#include <string.h>

#include "../data_structure/stack.h"
#include "../data_structure/queue.h"

typedef struct TInquiry {
    char Name[10]; // имя запроса
    unsigned Time; // время обслуживания
    char T; // тип задачи: 1 — Т1, 2 — Т2, 3 — Т3
} TInquiry;

typedef struct Processor {
    TInquiry *task;
    unsigned time_left;
} Processor;

/*
 * Система состоит из двух процессоров P1 и P2, трех очередей F1, F2, F3 и стека. В систему
 * могут поступать запросы на выполнение задач трех типов — Т1, Т2, Т3. Задача типа Т1 может
 * выполняться только процессором P1. Задача типа Т2 может выполняться только процессором P2.
 * Задача типа Т3 может выполняться любым процессором. Запрос можно представить записью TInquiry.
 * Поступающие запросы ставятся в соответствующие типам задач очереди. Если очередь F1 не пуста
 * и процессор P1 свободен, то задача из очереди F1 поступает на обработку в процессор P1. Если
 * процессор Р1 обрабатывает задачу типа Т3, а процессор Р2 свободен и очередь F2 пуста, то задача
 * из процессора Р1 поступает в процессор Р2, а задача из очереди F1 в процессор Р1, если же процессор
 * Р2 занят или очередь F2 не пуста, то задача из процессора Р1 помещается в стек.
 * Если очередь F2 не пуста и процессор P2 свободен, то задача из очереди F2 поступает на обработку
 * в процессор P2. Если процессор Р2 обрабатывает задачу типа Т3, а процессор Р1 свободен и очередь
 * F1 пуста, то задача из процессора Р2 поступает в процессор Р1, а задача из очереди F2 — в процессор
 * Р2, если же процессор Р1 занят или очередь F1 не пуста, то задача из процессора Р1 помещается в стек.
 * Если очередь F3 не пуста и процессор P1 свободен, и очередь F1 пуста или свободен процессор Р2
 * и очередь F2 пуста, то задача из очереди F3 поступает на обработку в свободный процессор. Задача
 * из стека поступает на обработку в свободный процессор Р1, если очередь F1 пуста, или в
 * свободный процессор Р2, если очередь F2 пуста.
 */
void simulate(unsigned N);

#endif //ALGORITMS_AND_DS_LAB6_H