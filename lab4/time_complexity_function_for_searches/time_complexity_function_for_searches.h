//
// Created by Artyom on 19.10.2023.
//

#ifndef ALGORITMS_AND_DS_TIME_COMPLEXITY_FUNCTION_FOR_SEARCHES_H
#define ALGORITMS_AND_DS_TIME_COMPLEXITY_FUNCTION_FOR_SEARCHES_H

#include <stdio.h>
#include <stdlib.h>

#include "../searches_for_tcf/searches_for_tcf.h"
#include "../../standart_functions/standart_functions.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct search_function {
    long long (*search)(long long*, size_t, long long);

    char *name;
} search_function;

typedef struct generation_function {
    void (*generate)(int *, size_t);

    char *name;
} generation_function;

void time_experiment_for_searches();

#endif //ALGORITMS_AND_DS_TIME_COMPLEXITY_FUNCTION_FOR_SEARCHES_H
