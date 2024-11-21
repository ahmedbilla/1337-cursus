/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:29 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/20 16:44:38 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_p(unsigned long n, const char *base, size_t *len)
{
	if (n >= 16)
		ft_putnbr_base_p(n / 16, base, len);
	ft_putchar(base[n % 16], len);
}
