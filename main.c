#include <stdio.h>

#include "data_structure/sequential_linear_list.h"
#include "lab5/lab5.h"

typedef long long base_type; // Замените на нужный тип данных

// Здесь происходит запуск последней выполненной лабораторной работы
int main() {
    size_t n = 5;

    base_type arr_q[] = {1, 2, 3, 4, 5};
    SequentialLinearList *q = create_list(n);
    init_list(q, arr_q, n);
    output_list(q);

    base_type arr_r[] = {6, 7, 8, 9, 10};
    SequentialLinearList *r = create_list(n);
    init_list(r, arr_r, n);

    SequentialLinearList *p = sum_polynomials(q, r);

    output_list(p);

    delete_list(q);
    delete_list(r);
    delete_list(p);

    return 0;
}