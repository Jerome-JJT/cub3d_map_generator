/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:52 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:52 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (ptr != NULL)
		ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}
