//
// Created by Artyom on 15.10.2023.
//

#include "lab3.h"

void check_time(long long (*sort_func)(int *, int), void (*generate_func)(int *, size_t), size_t size,
                char *experiment_name) {
    static size_t run_counter = 1;
    static int inner_buffer[100000000];

    generate_func(inner_buffer, size);

    printf("Run #%zu | ", run_counter++);
    printf("Name: %s\n", experiment_name);

    long long count_comparison = sort_func(inner_buffer, size);

    printf("Status: ");

    if (is_ordered(inner_buffer, size)) {
        printf("OK! Count comparison %lld\n\n", count_comparison);

        char filename[256];

        sprintf(filename, "data/%s.csv", experiment_name);

        FILE *f = fopen(filename, "a");

        if (f == NULL) {
            printf("File open error %s", filename);

            exit(1);
        }

        fprintf(f, "%llu; %lld\n", size, count_comparison);

        fclose(f);
    } else {
        printf("Wrong!\n");

        output_array(inner_buffer, size);
        exit(1);
    }
}


void time_experiment() {
    sort_function sorts[] = {
            {sis,        "sis"},
            {str_sel,    "str_sel"},
            {bbl_sort,   "bbl_sort"},
            {bbl_sort1,  "bbl_sort1"},
            {bbl_sort2,  "bbl_sort2"},
            {shell_sort, "shell_sort"},
            {hoar_sort,  "hoar_sort"},
            {heap_sort,  "heap_sort"},
    };
    const unsigned FUNCS_N = ARRAY_SIZE(sorts);
    generation_function generation[] = {
            {generate_random_array, "random"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generation);

    for (size_t size = 5; size <= 45; size += 5) {
        printf("**************************************\n");
        printf("size: %llu\n", size);

        for (size_t i = 0; i < FUNCS_N; i++)
            for (size_t j = 0; j < CASES_N; j++) {
                static char filename[128];

                sprintf(filename, "%s_%s_time", sorts[i].name, generation[j].name);

                check_time(sorts[i].sort, generation[j].generate, size,
                           filename);
            }

        printf("\n");
    }
}
