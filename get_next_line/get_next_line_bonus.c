/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:08:16 by ahbilla           #+#    #+#             */
/*   Updated: 2024/12/15 22:26:17 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	read_from_file(ssize_t *bytesread, char	**leftover, int fd)
{
	char	*buffer;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	*bytesread = read(fd, buffer, BUFFER_SIZE);
	if (*bytesread < 0)
	{
		free(buffer);
		if (*leftover)
		{
			free(*leftover);
			*leftover = NULL;
		}
		return ;
	}
	while (*bytesread > 0)
	{
		buffer[*bytesread] = '\0';
		*leftover = ft_strjoin(*leftover, buffer);
		if (ft_strchr(*leftover, '\n'))
			break ;
		*bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
}

static char	*check_line(char **leftover)
{
	char	*endline;
	char	*tmp;
	char	*line;

	if (!leftover || !*leftover)
		return (NULL);
	endline = ft_strchr(*leftover, '\n');
	if (endline)
	{
		line = ft_strdup(*leftover, endline - *leftover + 1);
		tmp = ft_strdup(endline + 1, ft_strlen(endline + 1));
		free(*leftover);
		*leftover = tmp;
	}
	else
	{
		line = ft_strdup(*leftover, ft_strlen(*leftover));
		free(*leftover);
		*leftover = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*leftover[OPEN_MAX];
	ssize_t		bytesread;
	char		*output_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_from_file(&bytesread, &leftover[fd], fd);
	if (bytesread < 0 || (bytesread == 0 && (!leftover[fd] || leftover[fd][0] == '\0')))
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (NULL);
	}
	output_line = check_line(&leftover[fd]);
	return (output_line);
}