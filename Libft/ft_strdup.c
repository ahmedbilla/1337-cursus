/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:03:38 by ahbilla           #+#    #+#             */
/*   Updated: 2024/11/04 22:13:50 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	size_t	i;
	char	*arr;

	lenght = ft_strlen(s1);
	i = 0;
	arr = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!arr)
	{
		return (NULL);
	}
	while (i < lenght)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
