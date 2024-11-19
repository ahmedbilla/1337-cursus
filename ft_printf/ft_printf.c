/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:54:30 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/19 23:34:06 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
    {
        return 0;
    }
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}
int ft_printf(const char *format, ...)
{
    va_list arg;
    va_start(arg, format);
    int i = 0;
    size_t len;
    if (write(1, 0, 0) == -1)
        return -1;
    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'c')
        {
            ft_putchar(va_arg(arg, int), &len);
            i++;
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 's')
        {
            char *str = va_arg(arg, char *);

            if (!str)
            {
                write(1, "(null)", 6);
                return 6;
            }
            if (str)
            {
                ft_putstr(str, &len);
                i += ft_strlen(str);
            }
            format += 2;
        }
       if ((*format == '%' && *(format + 1) == 'd') || *(format + 1) == 'i')
        {
            ft_putnbr(va_arg(arg, int), &len);
            i++;
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 'p')
        {
            ft_putptr((unsigned long)va_arg(arg, void *));
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 'u')
        {
            ft_putnbr_base_x(va_arg(arg, unsigned long));
            i++;
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 'x')
        {
            ft_putnbr_base_x((unsigned long)va_arg(arg, void *));
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == 'X')
        {
            ft_putnbr_base_x_up((unsigned long)va_arg(arg, void *));
            format += 2;
        }
        else if (*format == '%' && *(format + 1) == '%')
        {
            ft_putchar('%',&len);
            i++;
            format += 2;
        }
        else if (*format == '%')
        {
            ft_putchar('%', &len);
            i++;
            format++;
        }
        else
        {
            ft_putchar(*format, &len);
            i++;
            format++;
        }
    }
    return len;
}

int main()
{
        void *ptr = (void *)0154554;
        printf("%p\n", ptr);
        ft_printf("%p\n", ptr);

        printf("==============\n");

        printf("%c\n", 'a');
        ft_printf("%c\n", 'a');

        printf("==============\n");

    printf("%s\n", (char *)NULL);
    ft_printf("%s\n", (char *)NULL);

        printf("==============\n");

int i = printf("%d\n", -10);
       int a =   ft_printf("%d\n", -10);
    printf("i = %d and a = %d", i, a);
        printf("==============\n");

        printf("%i\n", 123456789);
        ft_printf("%i\n", 123456789);

        printf("==============\n");
        printf("%u\n", 12345);
        ft_printf("%u\n", 12345);

        printf("==============\n");
        printf("%x\n", 21478);
        ft_printf("%x\n", 21478);

        printf("==============\n");
        printf("%X\n", 21478);
        ft_printf("%X\n", 21478);

        printf("==============\n");
        printf("%%\n");
        ft_printf("%%\n");
        return 0;
}
