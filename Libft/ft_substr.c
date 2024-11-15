/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:56:18 by ahbilla           #+#    #+#             */
/*   Updated: 2024/10/30 15:16:21 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_substring(const char *s, char *array,
	unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			array[j] = s[i];
			j++;
		}
		i++;
	}
	array[j] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		array = (char *)malloc(sizeof(char));
		if (array != NULL)
		{
			array[0] = '\0';
		}
		return (array);
	}
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	copy_substring(s, array, start, len);
	return (array);
}
