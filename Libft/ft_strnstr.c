/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 00:15:56 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/01 16:37:40 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *str_to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str_to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] != '\0' && str_to_find[j] != '\0'
			&& str[i + j] == str_to_find[j] && (i + j) < len)
			j++;
		if (str_to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
