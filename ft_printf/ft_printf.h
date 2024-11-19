/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:33:44 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 23:24:52 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libc.h>


void ft_putchar(char c, size_t *len);
void ft_putstr(char *str, size_t *len);
void ft_putnbr(int n, size_t *len);
void ft_putptr(unsigned long ptr);
void ft_putunsigned(unsigned long n, size_t *len);
void ft_putnbr_base_x(unsigned long num);
void ft_putnbr_base_x_up(unsigned long num);


#endif