//
// Created by Artyom on 16.11.2023.
//

#include "lab7.h"

size_t calc_level(Tree t, size_t level) {
    if (!t)
        return 0;

    if (!level)
        return 1;

    return calc_level(mem_tree[t].l_son, level - 1) + calc_level(mem_tree[t].r_son,
                                                                 level - 1);
}

void print_path(int path[], int path_len) {
    int i;

    for (i = path_len - 1; i >= 0; i--)
        printf("%d ", path[i]);

    printf("\n");
}

void print_paths_recur(Tree t, int path[], int path_len) {
    if (!t)
        return;

    path[path_len] = *(int *) mem_tree[t].data; // явное приведение типа
    path_len++;

    if (!mem_tree[t].l_son && !mem_tree[t].r_son)
        print_path(path, path_len);
    else {
        print_paths_recur(mem_tree[t].l_son, path, path_len);
        print_paths_recur(mem_tree[t].r_son, path, path_len);
    }
}

void write_ways(Tree t) {
    int path[1000];

    print_paths_recur(t, path, 0);
}