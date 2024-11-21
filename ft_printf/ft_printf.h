/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:33:44 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/21 01:18:08 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, size_t *len);
void	ft_putstr(char *str, size_t *len);
void	ft_putnbr_base_p(unsigned long n, const char *base, size_t *len);
void	ft_putnbr(int n, size_t *len);
void	ft_putunsigned(unsigned int n, size_t *len);
void	ft_putnbr_base_x(unsigned int n, const char *base, size_t *len);

#endif