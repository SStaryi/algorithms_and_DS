//
// Created by Artyom on 01.11.2023.
//

#include "lab5.h"

SequentialLinearList *sum_polynomials(SequentialLinearList *q, SequentialLinearList *r) {
    // Создаем новый список для хранения результата.
    SequentialLinearList *p = create_list(q->capacity > r->capacity ? q->capacity :
                                          r->capacity);

    // Суммируем коэффициенты для каждой степени x.
    for (size_t i = 0; i < p->capacity; i++) {
        base_type q_coef = i < q->size ? get(q, i) : 0;
        base_type r_coef = i < r->size ? get(r, i) : 0;
        base_type sum_coef = q_coef + r_coef;

        // Если суммарный коэффициент не равен нулю, добавляем его в результат.
        if (sum_coef != 0)
            insert(p, sum_coef, i);
    }

    return p;
}