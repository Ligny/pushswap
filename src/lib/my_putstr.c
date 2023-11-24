/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2022-11-23 15:38:27
 * @ Description:
 */

#include "../../include/pushswap.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i ++)
        my_putchar(str[i]);
}