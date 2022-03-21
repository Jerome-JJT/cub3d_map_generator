/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:44:26 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/11/01 15:44:26 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);

void	ft_empty_buffer(char *buffer, char **newline);
int		ft_gnl_init(char **buffer, int *road, int fd);
void	ft_full_free(void **ptr);

size_t	ft_gnl_strlen(const char *str);
char	*ft_strjoin_free(char *s1, char *s2);
size_t	ft_strchr_int(const char *str, int c);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);

#endif
