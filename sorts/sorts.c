//
// Created by Artyom on 15.10.2023.
//

#include "sorts.h"

/*============СОРТИРОВКА ВКЛЮЧЕНИЕМ=============*/

/* функция сортировки включением  */
long long sis(int A[], int nn) {
    long long number_of_comparisons = 0;
    int i, j, k;

    for (j = 1; j < nn; j++) {
        k = A[j];
        i = j - 1;

        while (k < A[i] && i >= 0) {
            number_of_comparisons++;

            A[i + 1] = A[i];
            i -= 1;
        }

        number_of_comparisons++;

        A[i + 1] = k;
    }

    return number_of_comparisons + (nn - 1);
}
/*==============СОРТИРОВКА ВЫБОРОМ===============*/

/*функция сортировки выбором  */
long long str_sel(int A[], int nn) {
    long long number_of_comparisons = 0;
    int i, j, x, k;

    for (i = 0; i < nn - 1; i++) {
        x = A[i];
        k = i;

        for (j = i + 1; j < nn; j++)
            if (A[j] < x) {
                k = j;
                x = A[k];
            }

        number_of_comparisons += (nn - (i + 1));

        A[k] = A[i];
        A[i] = x;
    }

    return number_of_comparisons + (nn - 1);
}


/*============СОРТИРОВКА ОБМЕНОМ=============*/

/*  функция сортировки обменом  */
long long bbl_sort(int A[], int nn) {
    long long number_of_comparisons = 0;
    int i, j, k, p;

    for (i = 0; i < nn - 1; i++) {
        p = 0;

        for (j = nn - 1; j > i; j--) {
            number_of_comparisons++;

            if (A[j] < A[j - 1]) {
                k = A[j];
                A[j] = A[j - 1];
                A[j - 1] = k;
                p = 1;
            }
        }

        number_of_comparisons += (nn - i);

        /* Если перестановок не было, то сортировка выполнена */
        if (!p)
            break;
    }

    return number_of_comparisons + (nn - 1);
}


long long bbl_sort1(int arr[], int n) {
    long long number_of_comparisons = 0;
    int temp;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            number_of_comparisons++;

            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        number_of_comparisons += (n - i);

        // если на текущей итерации не было ни одного обмена,
        // то массив уже отсортирован и можно завершить процесс
        if (swapped == false)
            break;
    }

    return number_of_comparisons + (n - 1);
}


long long bbl_sort2(int arr[], int n) {
    long long number_of_comparisons = 0;
    int i, j, temp;
    int last_swap_index = n - 1;

    for (int i = 0; i < n - 1; i++) {
        int current_swap_index = -1;

        for (int j = 0; j < last_swap_index; j++) {
            number_of_comparisons++;

            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                current_swap_index = j;
            }
        }

        number_of_comparisons += (last_swap_index + 1);

        // если на текущей итерации не было ни одного обмена,
        // то массив уже отсортирован и можно завершить процесс
        if (current_swap_index == -1)
            break;

        last_swap_index = current_swap_index;
    }

    return number_of_comparisons + (n - 1);
}

/*============СОРТИРОВКА МЕТОДОМ ШЕЛЛА=============*/

// Функция для сортировки массива методом Шелла
long long shell_sort(int arr[], int n) {
    long long number_of_comparisons = 0;

    // Начинаем с большего шага
    for (int gap = n / 2; gap > 0; gap /= 2) {
        number_of_comparisons++;

        // Проходим по элементам массива с шагом gap
        for (int i = gap; i < n; i++) {
            // Сохраняем текущий элемент в переменную temp
            int temp = arr[i];

            // Сдвигаем предыдущие элементы, которые больше текущего, на один шаг вперед
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                number_of_comparisons++;
                arr[j] = arr[j - gap];
            }

            number_of_comparisons++;
            // Вставляем текущий элемент на правильную позицию
            arr[j] = temp;
        }

        number_of_comparisons += (n - gap);
    }

    return number_of_comparisons + 1;
}


/*============СОРТИРОВКА МЕТОДОМ ХОАРА=============*/

/* Эта функция принимает последний элемент в качестве опорного, помещает
этот элемент в правильное положение в отсортированном массиве и помещает
все меньшие (меньше опорного) элементы слева от него и все большие
элементы справа от него */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // опорный элемент
    int i = (low - 1); // индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j], sizeof(arr[i]));
        }
    }

    swap(&arr[i + 1], &arr[high], sizeof(arr[i + 1]));

    return (i + 1);
}

/* Функция для реализации алгоритма быстрой сортировки
arr[] --> Массив для сортировки,
low  --> Начальный индекс,
high  --> Конечный индекс */
long long q_sort(int arr[], int low, int high, long long number_of_comparisons) {
    if (low < high) {
        /* pi - это разделительный индекс, arr[p] сейчас на правильном месте */
        int pi = partition(arr, low, high);

        number_of_comparisons += (2 * (high - low));
        // Рекурсивно сортируем элементы до разделителя и после разделителя
        q_sort(arr, low, pi - 1, number_of_comparisons);
        q_sort(arr, pi + 1, high, number_of_comparisons);
    }

    return number_of_comparisons + 1;
}

long long hoar_sort(int arr[], int high) {
    return q_sort(arr, 0, high, 0);
}

/*============ПИРАМИДАЛЬНАЯ СОРТИРОВКА=============*/


/* ============================================ */
void sift(int A[], int L, int R) {
    int i, j, x, k;

    i = L;
    j = 2 * L + 1;
    x = A[L];

    if ((j < R) && (A[j] < A[j + 1]))
        j++;

    while ((j <= R) && (x < A[j])) {
        k = A[i];
        A[i] = A[j];
        A[j] = k;
        i = j;
        j = 2 * j + 1;

        if ((j < R) && (A[j] < A[j + 1]))
            j++;
    }
}


/* ***************************************************** */

/* пирамидальная функция сортировки  */
long long heap_sort(int A[], int nn) {
    long long number_of_comparisons = 0;
    int L, R, x, i;

    L = nn / 2;
    R = nn - 1;

    /*  Построение пирамиды из исходного массива */
    while (L > 0) {
        number_of_comparisons++;
        L = L - 1;
        sift(A, L, R);
    }

    number_of_comparisons++;

    /* Сортировка: пирамида => отсортированный массив */
    while (R > 0) {
        number_of_comparisons++;
        x = A[0];
        A[0] = A[R];
        A[R] = x;
        R--;
        sift(A, L, R);
    }

    return number_of_comparisons + 1;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;

    if (arg1 > arg2)
        return 1;

    return 0;
}