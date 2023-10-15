//
// Created by Artyom on 15.10.2023.
//

#include "lab1.h"

void set_of_values() {
    long a_max = 57;
    long a_min = -41;

    double b = 12.5;

    enum Animal c = cat, d = dog, e = mouse, f = tiger;
}

void print_byte(unsigned char a) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }

    printf(" ");
}

void print_var(void *a, unsigned size) {
    unsigned char *p = a;

    for (int i = size - 1; i >= 0; i--) {
        print_byte(*(p + i));
    }

    printf("\n");
}

void bin_representation_of_ds() {
    long l = 57;
    long m = -41;
    double d = 3.14159265358979323846;
    Animal animal = tiger;

    printf("Binary representation of long l:\n");
    print_var(&l, sizeof(l));

    printf("Binary representation of long m:\n");
    print_var(&m, sizeof(m));

    printf("Binary representation of double d:\n");
    print_var(&d, sizeof(d));

    printf("Binary representation of Animal animal:\n");
    print_var(&animal, sizeof(animal));
}