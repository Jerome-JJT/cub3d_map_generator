/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:52 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:52 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = malloc(s1len + s2len + 1);
	if (ptr != NULL)
	{
		ft_strlcpy(ptr, s1, s1len + 1);
		ft_strlcpy(ptr + s1len, s2, s2len + 1);
	}
	ptr[s1len + s2len] = '\0';
	return (ptr);
}
