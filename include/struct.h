/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 21:47:25
 * @ Description:
 */

#pragma once

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node_t;

typedef struct save
{
    int i;
    int k;
} save_t;