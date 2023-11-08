//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <malloc.h>
//
//#include "str.h"
//
//void init_str(string1 st, unsigned n) {
//    st->max = n;
//    st->s = (char *) malloc(n + 2);
//
//    if (st->s == NULL) {
//        str_error = 1; // Нет памяти
//
//        return;
//    }
//
//    *(unsigned *) st->s = 0;
//    st->s[2] = '\0';
//}
//
//void write_to_str(string1 st, char *s) {
//    unsigned len = strlen(s);
//
//    if (len > st->max) {
//        str_error = 2; // Слишком длинная строка
//
//        return;
//    }
//
//    *(unsigned *) st->s = len;
//    strcpy(st->s + 2, s);
//}
//
//void write_from_str(char *s, string1 st) {
//    strcpy(s, st->s + 2);
//}
//
//void input_str(string1 st) {
//    gets(st->s + 2);
//    *(unsigned *) st->s = strlen(st->s + 2);
//}
//
//void output_str(string1 st) {
//    printf("%s", st->s + 2);
//}
//
//int comp(string1 s1, string1 s2) {
//    return strcmp(s1->s + 2, s2->s + 2);
//}
//
//void delete(string1 s, unsigned index, unsigned count) {
//    unsigned len = *(unsigned *) s->s;
//
//    if (index > len || index + count > len) {
//        str_error = 3; // Ошибка параметров
//
//        return;
//    }
//
//    memmove(s->s + index + 2, s->s + len + 2 - count, count);
//    *(unsigned *) s->s = len - count;
//}
//
//void insert_singly(string1 subs, string1 s, unsigned index) {
//    unsigned len = *(unsigned *) s->s;
//
//    if (index > len) {
//        str_error = 3; // Ошибка параметров
//
//        return;
//    }
//
//    if (len + *(unsigned *) subs->s > s->max) {
//        str_error = 2; // Слишком длинная строка
//
//        return;
//    }
//
//    memmove(s->s + len + 2 + *(unsigned *) subs->s, s->s + index + 2, len - index);
//    memcpy(s->s + index + 2, subs->s + 2, *(unsigned *) subs->s);
//    *(unsigned *) s->s = len + *(unsigned *) subs->s;
//}
//
//void concat(string1 s1, string1 s2, string1 srez) {
//    unsigned len = *(unsigned *) s1->s + *(unsigned *) s2->s;
//
//    if (len > srez->max) {
//        str_error = 2; // Слишком длинная строка
//        return;
//    }
//
//    memcpy(srez->s + 2, s1->s + 2, *(unsigned *) s1->s);
//    memcpy(srez->s + 2 + *(unsigned *) s1->s, s2->s + 2, *(unsigned *) s2->s);
//    *(unsigned *) srez->s = len;
//}
//
//void copy(string1 s, unsigned index, unsigned count, string1 subs) {
//    unsigned len = *(unsigned *) s->s;
//
//    if (index > len || index + count > len) {
//        str_error = 3; // Ошибка параметров
//
//        return;
//    }
//
//    if (count > subs->max) {
//        str_error = 2; // Слишком длинная строка
//
//        return;
//    }
//
//    memcpy(subs->s + 2, s->s + index + 2, count);
//    *(unsigned *) subs->s = count;
//}
//
//unsigned length(string1 s) {
//    return *(unsigned *) s->s;
//}
//
//unsigned pos(string1 sub_s, string1 s) {
//    char *p = strstr(s->s + 2, sub_s->s + 2);
//
//    if (p == NULL)
//        return 0;
//    else
//        return p - s->s - 2;
//}
//
//void done_str(string1 s) {
//    free(s->s);
//}
