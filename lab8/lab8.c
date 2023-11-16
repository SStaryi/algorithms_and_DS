#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab8.h"

int strcmp_wrapper(void *a, void *b) {
    return strcmp((const char *) a, (const char *) b);
}

void process_line(char *line, Table *t) {
    char command[MAX_VAR_NAME_LENGTH];
    char var1[MAX_VAR_NAME_LENGTH];
    char var2[MAX_VAR_NAME_LENGTH];
    double value;

    if (sscanf(line, "%s %s %s", command, var1, var2) == 3) {
        if (!strcmp(command, "MOV")) {
            // Получение значения из переменной var2
            double value;

            if (get_table(t, &value, var2, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var2);

                return;
            }

            // Копирование значения в переменную var1
            if (put_table(t, &value, var1, strcmp_wrapper)) {
                printf("Mistake: failed to write value to %s variable\n", var1);

                return;
            }
        } else if (!strcmp(command, "ADD")) {
            // Получение значений из переменных var1 и var2
            double value1, value2;

            if (get_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var1);

                return;
            }

            if (get_table(t, &value2, var2, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var2);

                return;
            }

            // Сложение значений и сохранение результата в var1
            value1 += value2;

            if (put_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Mistake: failed to write value to %s variable\n", var1);

                return;
            }
        } else if (!strcmp(command, "SUB")) {
            // Получение значений из переменных var1 и var2
            double value1, value2;

            if (get_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var1);

                return;
            }

            if (get_table(t, &value2, var2, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var2);

                return;
            }

            // Вычитание значения var2 из var1 и сохранение результата в var1
            value1 -= value2;

            if (put_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Mistake: failed to write value to %s variable\n", var1);

                return;
            }
        } else if (!strcmp(command, "MUL")) {
            // Получение значений из переменных var1 и var2
            double value1, value2;

            if (get_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var1);

                return;
            }

            if (get_table(t, &value2, var2, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var2);

                return;
            }

            // Умножение значения var1 на var2 и сохранение результата в var1
            value1 *= value2;

            if (put_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Mistake: failed to write value to %s variable\n", var1);

                return;
            }
        } else if (!strcmp(command, "DIV")) {
            // Получение значений из переменных var1 и var2
            double value1, value2;

            if (get_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var1);

                return;
            }

            if (get_table(t, &value2, var2, strcmp_wrapper)) {
                printf("Error: variable %s not found\n", var2);

                return;
            }

            // Проверка деления на ноль
            if (!value2) {
                printf("Error: Division by zero\n");

                return;
            }

            // Деление значения var1 на var2 и сохранение результата в var1
            value1 /= value2;

            if (put_table(t, &value1, var1, strcmp_wrapper)) {
                printf("Mistake: failed to write value to %s variable\n", var1);

                return;
            }
        }
    } else if (sscanf(line, "%s %s", command, var1) == 2) {
        if (!strcmp(command, "IN")) {
            printf("Enter a value for %s: ", var1);

            scanf("%lf", &value);

            // Добавить значение в таблицу
            if (put_table(t, &value, var1, strcmp_wrapper))
                printf("Mistake: failed to write value to %s variable\n", var1);
        } else if (!strcmp(command, "OUT")) {
            // Получить значение из таблицы
            double value;

            if (get_table(t, &value, var1, strcmp_wrapper))
                printf("Error: variable %s not found\n", var1);
            else
                // Вывести значение
                printf("%s = %lf\n", var1, value);
        }
    }
}