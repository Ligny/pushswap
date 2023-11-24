/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 21:49:57
 * @ Description:
 */

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "struct.h"

#define RETURN_EPITECH_ERROR 84
#define RETURN_SUCCESS 0

int pushswap_algorithm(int argc, char **argv);
void pos(node_t **l_a, node_t **l_b, save_t *save, int len);
void neg(node_t **l_a, node_t **l_b, save_t *save, int len);
bool is_sorted(node_t *node, int size);
void print_list(node_t *node, int argc, char *str_list);

void add_to_list(char **argv, node_t **node_first, node_t **node_last, node_t **node);
void free_node(node_t **node, int len);
struct node *create_node(char **argv);

void push_to_list(node_t **from, node_t **to);
void first_to_end(node_t **l_a);
void end_to_first(node_t **l_a);

int my_atoi(char const *str);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);