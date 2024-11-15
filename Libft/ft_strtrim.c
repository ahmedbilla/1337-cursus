/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:54:48 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/07 00:18:10 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static void	copysubstring(char *arr, const char *str, int start, int end)
{
	int	j;

	j = 0;
	while (j < (end - start))
	{
		arr[j] = str[start + j];
		j++;
	}
	arr[j] = '\0';
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	lenght;
	char	*arr;
	size_t	start;
	size_t	j;
	size_t	end ;

	if (!str || !set)
		return (NULL);
	lenght = ft_strlen(str);
	start = 0;
	j = 0;
	end = lenght;
	if (!str || !set)
		return (NULL);
	while (str[start] && is_set(str[start], set))
		start++;
	while (end > start && is_set(str[end - 1], set))
	{
		end--;
	}
	arr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!arr)
		return (NULL);
	copysubstring(arr, str, start, end);
	return (arr);
}
