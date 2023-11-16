#include <stdio.h>

#include "data_structure/table.h"
#include "lab8/lab8.h"

// Здесь находится реализация последней выполненной лабораторной работы
int main() {
    Table t;
    init_table(&t, 100, sizeof(double));

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), stdin))
        process_line(line, &t);

    done_table(&t);

    return 0;
}
