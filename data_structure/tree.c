#include "tree.h"

Element mem_tree[TREE_BUFFER_SIZE];
int tree_error = TREE_OK;
size_t Size = 0;

Tree init_tree(unsigned size) {
    if (size < 1) {
        tree_error = TREE_UNDER;

        return 0;
    }

    if (size > TREE_BUFFER_SIZE) {
        tree_error = TREE_NOT_MEM;

        return 0;
    }

    Size = size;

    tree_error = TREE_OK;
    init_mem();

    return 0;
}

void init_mem() {
    tree_error = TREE_OK;

    if (Size < 1) {
        tree_error = TREE_UNDER;

        return;
    }

    if (Size > TREE_BUFFER_SIZE) {
        tree_error = TREE_NOT_MEM;

        return;
    }

    for (Ptr_El i = 0; i < Size - 1; i++)
        mem_tree[i].l_son = i + 1;

    mem_tree[Size - 1].l_son = 0;
}

Tree create_root() {
    tree_error = TREE_OK;

    size_t new_ind = new_mem();

    if (tree_error != TREE_OK)
        return 0;

    mem_tree[new_ind].r_son = 0;
    mem_tree[new_ind].l_son = 0;

    return new_ind;
}


int empty_mem() {
    tree_error = TREE_OK;

    return mem_tree[0].l_son == 0;
}

size_t new_mem() {
    tree_error = TREE_OK;

    Ptr_El result = mem_tree[0].l_son;

    if (!result) {
        tree_error = TREE_NOT_MEM;

        return 0;
    }

    mem_tree[0].l_son = mem_tree[result].l_son;

    return result;
}

void dispose_mem(size_t n) {
    tree_error = TREE_OK;

    if (!n)
        return;

    Ptr_El oldElement = mem_tree[0].l_son;

    mem_tree[0].l_son = n;
    mem_tree[n].l_son = oldElement;
}

void write_data_tree(Tree t, Tree_Base_Type e) {
    tree_error = TREE_OK;
    mem_tree[t].data = e;
}

Tree_Base_Type read_data_tree(Tree t) {
    tree_error = TREE_OK;

    return mem_tree[t].data;
}

int is_l_son(Tree t) {
    tree_error = TREE_OK;

    return mem_tree[t].l_son != 0;
}

int is_r_son(Tree t) {
    tree_error = TREE_OK;

    return mem_tree[t].r_son != 0;
}

Tree move_to_l_son(Tree t) {
    if (is_l_son(t))
        return mem_tree[t].l_son;

    tree_error = TREE_UNDER;

    return 0;
}

Tree move_to_r_son(Tree t) {
    if (is_r_son(t))
        return mem_tree[t].r_son;

    tree_error = TREE_UNDER;

    return 0;
}

int is_empty_tree(Tree t) {
    tree_error = TREE_OK;

    return !mem_tree[t].r_son && !mem_tree[t].l_son;
}

void del_tree(Tree t) {
    tree_error = TREE_OK;

    if (!t)
        return;

    del_tree(mem_tree[t].r_son);
    del_tree(mem_tree[t].l_son);

    dispose_mem(t);
}

#define NAME_BUFFER_SIZE 100

int build_tree(Tree t, char *input) {
    mem_tree[t].l_son = 0;

    char *startInput = input;

    while (isspace(*input))
        input++;

    if (*input != '(')
        return -1;

    input++;

    char *buffer = calloc(NAME_BUFFER_SIZE, sizeof(char));
    int bufferIndex = 0;
    bool shouldWriteData = true;
    bool anyChild = false;

    while (*input != ')')
        if (*input == '\0')
            return -1;
        else if (*input == '(') {
            if (shouldWriteData) {
                write_data_tree(t, buffer);
                shouldWriteData = false;
            }

            size_t newIndex = new_mem();

            if (!anyChild) {
                anyChild = true;
                mem_tree[t].l_son = newIndex;
            } else
                mem_tree[t].r_son = newIndex;

            int res = build_tree(newIndex, input);

            if (res == -1)
                return -1;

            input += res + 1;
            t = newIndex;
            mem_tree[t].r_son = 0;
        } else if (shouldWriteData)
            buffer[bufferIndex] = *(input++);
        else
            input++;

    if (shouldWriteData)
        write_data_tree(t, buffer);

    return input - startInput;
}

void copy_tree(Tree dst, Tree src) {
    write_data_tree(dst, read_data_tree(src));

    if (tree_error != TREE_OK)
        return;

    Tree r_son = move_to_r_son(src);
    mem_tree[dst].r_son = r_son;

    if (is_r_son(src) && tree_error == TREE_OK) {
        Tree new_tree = new_mem();

        if (tree_error != TREE_OK)
            return;

        mem_tree[dst].r_son = new_tree;

        copy_tree(new_tree, r_son);
    }

    Tree l_son = move_to_l_son(src);

    mem_tree[dst].l_son = l_son;

    if (is_l_son(src) && tree_error == TREE_OK) {
        Tree new_tree = new_mem();

        if (tree_error != TREE_OK)
            return;

        mem_tree[dst].l_son = new_tree;

        copy_tree(new_tree, l_son);
    }
}

bool comp_tree(Tree t1, Tree t2) {
    return ((read_data_tree(t1) == read_data_tree(t2)) && tree_error == TREE_OK) &&
           (is_r_son(t1) == is_r_son(t2) ? !is_r_son(t1) || comp_tree(mem_tree[t1].r_son,
                                                                      mem_tree[t2].r_son) : false) &&
           (is_l_son(t1) == is_l_son(t2) ? !is_l_son(t1) ||
                                           comp_tree(mem_tree[t1].l_son, mem_tree[t2].l_son) : false);
}