/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:41:39 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 23:15:21 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_hex_p(unsigned long num)
{
    char *hex = "0123456789abcdef";

    if (num >= 16)
    {   
        ft_putnbr_hex_p(num / 16);
    }
    char digit = hex[num % 16];
    write(1, &digit, 1);
}
void ft_putptr(unsigned long ptr)
{
    if (!ptr)
    {
        write(1, "0x0", 3);
        return;
    }
    write(1, "0x", 2);
    ft_putnbr_hex_p(ptr);
}
// #include <stdio.h>
// int main()
// {
//     void *ptr = (void *)0124;
//       printf("%p\n",ptr);
//     ft_putptr((unsigned long)ptr);
   

//     return 0;
// }