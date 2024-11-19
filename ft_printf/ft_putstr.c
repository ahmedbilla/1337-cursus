/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:36:00 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 23:23:08 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, size_t *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}
