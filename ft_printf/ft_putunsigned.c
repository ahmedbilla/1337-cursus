/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:24:46 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 18:24:48 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putunsigned(unsigned long n, size_t *len)

{
    if (n > 9) {
        ft_putunsigned(n / 10, len);
    }
    ft_putchar((n % 10) + '0', len);
}