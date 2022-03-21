/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:44:24 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/01 15:44:24 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	ft_empty_buffer(char *buffer, char **newline)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_gnl_strlen(buffer);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	*newline = malloc(sizeof(char) * (i + 1));
	while (j < len)
	{
		if (j < i)
			(*newline)[j] = buffer[j];
		if (i + j < len)
			buffer[j] = buffer[i + j];
		else
			buffer[j] = '\0';
		j++;
	}
	(*newline)[i] = '\0';
}

int	ft_gnl_init(char **buffer, int *road, int fd)
{
	if (*buffer == NULL)
	{
		*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		*road = 0;
		while (*road < BUFFER_SIZE + 1)
		{
			(*buffer)[*road] = '\0';
			(*road)++;
		}
	}
	if (ft_gnl_strlen(*buffer) == 0)
	{
		*road = read(fd, *buffer, BUFFER_SIZE);
		if (*road == -1)
		{
			ft_full_free((void **)buffer);
			return (0);
		}
	}
	else
		*road = BUFFER_SIZE;
	return (1);
}

void	ft_full_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*thisline;
	char		*newpart;
	int			road;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	thisline = NULL;
	ft_gnl_init(&(buffer[fd]), &road, fd);
	if (road > 0)
		ft_empty_buffer(buffer[fd], &thisline);
	while (road == BUFFER_SIZE && (ft_gnl_strlen(thisline) == 0
			|| thisline[ft_gnl_strlen(thisline) - 1] != '\n'))
	{
		road = read(fd, buffer[fd], BUFFER_SIZE);
		if (road > 0)
		{
			ft_empty_buffer(buffer[fd], &newpart);
			thisline = ft_strjoin_free(thisline, newpart);
		}
	}
	if (thisline == NULL || ft_gnl_strlen(buffer[fd]) == 0)
		ft_full_free((void **)&(buffer[fd]));
	return (thisline);
}
