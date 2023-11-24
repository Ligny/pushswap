/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-22 21:52:05
 * @ Description:
 */

#include "include/pushswap.h"

int main(int argc, char **argv)
{
    if (argc == 1) return (RETURN_EPITECH_ERROR);
    else return push_swap(argc, argv);
}