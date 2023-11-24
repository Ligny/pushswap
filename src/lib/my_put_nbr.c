/**
 * @ Author: Antoine Deligny
 * @ Create Time: 2021-11-23 15:31:00
 * @ Description:
 */

#include "../../include/pushswap.h"

void my_put_nbr(int nb)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        i = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(i + '0');
    } else
        my_putchar(nb + '0');
}