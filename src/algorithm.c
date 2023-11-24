/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2023-11-22 21:56:33
 * @ Description:
 */

#include "../include/pushswap.h"

void print_list(node_t *node, int argc, char *str_list)
{
    for (int j = 1; j < argc; j++) {
        if (node == NULL) {
            my_putstr(str_list);
            my_putstr(" : NULL\n");
            return;
        }
        my_putstr(str_list);
        my_put_nbr(node->data);
        my_putchar('\n');
        node = node->next;
    }
}

bool is_sorted(node_t *node, int size)
{
    int count = 0;

    for (int j = 1; j < size; j++) {
        if (node->data > node->next->data)
            count++;
        node = node->next;
    }
    node = node->next;
    if (count == 0)
        return (false);
    return (true);
}

void neg(node_t **l_a, node_t **l_b, save_t *save, int len)
{
    for (int j = 1; j <= len; j++) {
        if (((*l_a)->data >> 31) & 1) {
            push_to_list(l_a, l_b);
            write(1, "pb ", 3);
            save->k++;
        }
        else {
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
    if (l_b != NULL) {
        for (int j = 0; j < save->k; j++) {
            push_to_list(l_b, l_a);
            write(1, "pa ", 3);
        }
    }
}

void pos(node_t **l_a, node_t **l_b, save_t *save, int len)
{
    for (int j = 1; j <= len; j++) {
        if (((*l_a)->data >> save->i) & 1) {
            push_to_list(l_a, l_b);
            first_to_end(l_b);
            write(1, "pb rb ", 6);
            save->k++;
        }
        else {
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
    if (l_b != NULL) {
        for (int j = 0; j < save->k; j++) {
            push_to_list(l_b, l_a);
            write(1, "pa ", 3);
            first_to_end(l_a);
            write(1, "ra ", 3);
        }
    }
}

int pushswap_algorithm(int argc, char **argv)
{
    node_t *list_a = create_node(argv);
    node_t *list_b = NULL;
    save_t save;
    int size = argc - 1;

    if (is_sorted(list_a, size) == false) {
        write(1, "\n", 1);
        return (RETURN_SUCCESS);
    }
    for (save.i = 0; save.i < 31; save.i++) {
        save.k = 0;
        pos(&list_a, &list_b, &save, size);
    }
    save.k = 0;
    neg(&list_a, &list_b, &save, size);
    write(1, "rb\n", 3);
    disp_list(list_a, argc, "l_a : \0");
    disp_list(list_b, argc, "l_b : \0");
    free_node(&list_a, size);
    return (RETURN_SUCCESS);
}