/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-23 15:15:43
 * @ Description:
 */

#include "../include/pushswap.h"

void add_to_list(char **argv, node_t **node_first, node_t **node_last, node_t **node)
{
    node_t *new_node;

    for (int i = 2; argv[i] != NULL; i ++) {
        new_node = malloc(sizeof(node_t));
        new_node->data = my_atoi(argv[i]);
        new_node->next = *node_first;
        (*node)->next = new_node;
        *node_last = *node;
        *node = (*node)->next;
        (*node)->prev = *node_last;
    }
}

struct node *create_node(char **argv)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *node_last;
    node_t *node_first;

    node->data = my_atoi(argv[1]);
    node->prev = node;
    node->next = node;
    node_first = node;
    node_last = node;
    add_to_list(argv, &node_first, &node_last, &node);
    node_last = node;
    node = node->next;
    node->prev = node_last;
    return (node);
};

void free_node(node_t **node, int len)
{
    node_t *tmp;

    for (int i = 0; i < len; i++) {
        tmp = *node;
        *node = (*node)->next;
        free(tmp);
    }
}