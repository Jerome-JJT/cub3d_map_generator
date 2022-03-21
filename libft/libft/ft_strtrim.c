/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:54 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:54 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	trimstart;
	size_t	trimend;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trimstart = 0;
	while (ft_strchr(set, s1[trimstart]) != NULL && trimstart < ft_strlen(s1))
		trimstart++;
	trimend = ft_strlen(s1);
	while (ft_strchr(set, s1[trimend]) != NULL && trimend > trimstart)
		trimend--;
	ptr = malloc(trimend - trimstart + 2);
	if (ptr != NULL)
		ft_strlcpy(ptr, s1 + trimstart, trimend - trimstart + 2);
	return (ptr);
}
