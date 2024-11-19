/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:23:22 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 20:26:54 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_base_x(unsigned long num)
{
    char *hex = "0123456789abcdef";

    if (num >= 16)
    {   
        ft_putnbr_base_x(num / 16);
    }
    char digit = hex[num % 16];
    write(1, &digit, 1);
}