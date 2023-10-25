#include <stdio.h>

#include "lab4/test_searches/test_searches.h"
#include "lab4/time_complexity_function_for_searches/time_complexity_function_for_searches.h"

// Здесь происходит запуск последней выполненной лабораторной работы
int main() {
    test_linear_search();
    test_fast_linear_search();
    test_fast_linear_search_for_a_sorted_array();
    test_binary_search();
    test_block_search();

    time_experiment_for_searches();

    return 0;
}