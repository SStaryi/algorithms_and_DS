#ifndef TREE
#define TREE

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define TREE_BUFFER_SIZE 1000

#define TREE_OK 0
#define TREE_NOT_MEM 1
#define TREE_UNDER 2

typedef void *Tree_Base_Type;
typedef size_t Ptr_El;

typedef struct {
    Tree_Base_Type data;
    Ptr_El l_son;
    Ptr_El r_son;
} Element;

typedef Ptr_El Tree;

extern Element mem_tree[TREE_BUFFER_SIZE];
extern int tree_error;
extern size_t Size;

// инициализация дерева
Tree init_tree(unsigned size);

// создание корня
Tree create_root();

//запись данных
void write_data_tree(Tree t, Tree_Base_Type e);

//чтение
Tree_Base_Type read_data_tree(Tree t);

//1 — есть левый сын, 0 — нет
int is_l_son(Tree t);

//1 — есть правый сын, 0 — нет
int is_r_son(Tree t);

// перейти к левому сыну, где t — адрес ячейки, содержащей адрес текущей вершины, TS — адрес
// ячейки, содержащей адрес корня левого поддерева(левого сына)
Tree move_to_l_son(Tree t);

//перейти к правому сыну
Tree move_to_r_son(Tree t);

//1 — пустое дерево,0 — не пустое
int is_empty_tree(Tree t);

//удаление листа
void del_tree(Tree t);

/*связывает все элементы массива в список свободных элементов*/
void init_mem();

/*возвращает 1, если в массиве нет свободных элементов,0 — в противном случае*/
int empty_mem();

/*возвращает номер свободного элемента и исключает его из ССЭ*/
size_t new_mem();

/*делает n-й элемент массива свободным и включает его в ССЭ*/
void dispose_mem(size_t n);

// Строит дерево t по его скобочному представлению input
int build_tree(Tree t, char *input);

// Копирует дерево src в dst.
void copy_tree(Tree dst, Tree src);

// Возвращает true, если деревья t1 и t2 равны.
bool comp_tree(Tree t1, Tree t2);

// освобождение памяти, занятой деревом
void free_tree(Tree t);

#endif