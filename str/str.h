#if !defined(__FORM7_H)
#define __FORM7_H
const short str_ok = 0; // Определение исключительных ситуаций
const short str_empty = 1;
const short str_full = 2;

typedef struct str {
    char *s; /* Указатель на строку. Первые два байта строки s со-держат динамическую длину строки */
    unsigned max; /* Максимальное количество символов в строке, определяющееся при инициализации */
} str;

typedef str *string1;

void init_str(string1 st, unsigned n);

void write_to_str(string1 st, char *s);

void write_from_str(char *s, string1 st);

void input_str(string1 st);

void output_str(string1 st);

int comp(string1 s1, string1 s2);

void delete(string1 s, unsigned index, unsigned count);

void insert(string1 subs, string1 s, unsigned index);

void concat(string1 s1, string1 s2, string1 srez);

void copy(string1 s, unsigned index, unsigned count, string1 subs);

unsigned length(string1 s);

unsigned pos(string1 sub_s, string1 s);

void done_str(string1 s);

int str_error; // Переменная ошибок//...
#endif
