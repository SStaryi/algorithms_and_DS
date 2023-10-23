//
// Created by Artyom on 19.10.2023.
//

#include "time_complexity_function_for_searches.h"

void check_time(long long (*sort_func)(long long *, size_t, long long),
                void (*generate_func)(int *, size_t), size_t size, char *experiment_name) {
    static size_t run_counter = 1;
    static int inner_buffer[100000000];

    generate_func(inner_buffer, size);

    printf("Run #%zu | ", run_counter++);
    printf("Name: %s\n", experiment_name);

    long long count_comparison = sort_func(inner_buffer, size, -1);

    printf("Status: ");

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
}


void time_experiment_for_searches() {
    search_function searches[] = {
            {linear_search_for_tcf, "linear_search"},
            {fast_linear_search_for_tcf, "fast_linear_search"},
            {binary_search_for_tcf, "binary_search"},
            {block_search_for_tcf,  "block_search"},
            };
    const unsigned FUNCS_N = ARRAY_SIZE(searches);
    generation_function generation[] = {
            {generate_random_array, "random"}
    };
    const unsigned CASES_N = ARRAY_SIZE(generation);

    for (size_t size = 5; size <= 45; size += 5) {
        printf("**************************************\n");
        printf("Size: %llu\n", size);

        for (size_t i = 0; i < FUNCS_N; i++)
            for (size_t j = 0; j < CASES_N; j++) {
                static char filename[128];

                sprintf(filename, "%s_%s_time", searches[i].name, generation[j].name);

                check_time(searches[i].search, generation[j].generate, size,
                           filename);
            }

        printf("\n");
    }
}
