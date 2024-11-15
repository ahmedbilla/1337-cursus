/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:45:26 by ahbilla           #+#    #+#             */
/*   Updated: 2024/10/30 19:14:57 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*arr;
	unsigned int	i;

	len = ft_strlen(s);
	if (!s || !f)
	{
		return (NULL);
	}
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
