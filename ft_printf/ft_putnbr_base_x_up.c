/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_X_up.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:36:04 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 20:37:02 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr_base_x_up(unsigned long num)
{
    char *hex = "0123456789ABCDEF";

    if (num >= 16)
    {   
        ft_putnbr_base_x_up(num / 16);
    }
    char digit = hex[num % 16];
    write(1, &digit, 1);
}