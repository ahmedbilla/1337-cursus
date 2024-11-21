/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:23:22 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/20 16:45:16 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_x(unsigned int n, const char *base, size_t *len)
{
	if (n >= 16)
		ft_putnbr_base_x(n / 16, base, len);
	ft_putchar(base[n % 16], len);
}
