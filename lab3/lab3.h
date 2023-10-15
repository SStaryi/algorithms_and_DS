//
// Created by Artyom on 15.10.2023.
//

#ifndef ALGORITMS_AND_DS_LAB3_H
#define ALGORITMS_AND_DS_LAB3_H

#include <stdio.h>
#include <stdlib.h>

#include "../standart_functions/standart_functions.h"
#include "../sorts/sorts.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct sort_function {
    long long (*sort)(int[], int);

    char *name;
} sort_function;


typedef struct generation_function {
    void (*generate)(int *, size_t);

    char *name;
} generation_function;

void time_experiment();

#endif //ALGORITMS_AND_DS_LAB3_H
