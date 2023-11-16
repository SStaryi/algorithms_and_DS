#ifndef __TABLE_H
#define __TABLE_H

#include "tree.h"
#include "singly_linked_list.h"

#define TABLE_OK 0
#define TABLE_NOT_MEM 1
#define TABLE_UNDER 2

typedef Node *Table;
typedef char *T_Key; // Определить тип ключа
typedef int (*func)(void *, void *);

extern int table_error; // 0..2

void init_table(Table *t, unsigned size_mem, unsigned size_el);

inline int empty_table(Table *t);

int put_table(Table *t, void *e, T_Key key, func f);

int get_table(Table *t, void *e, T_Key key, func f);

int read_table(Table *t, void *e, T_Key key, func f);

int write_table(Table *t, void *e, T_Key key, func f);

void done_table(Table *t);

#endif
