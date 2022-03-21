/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:52 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:52 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && dest_len + i + 1 < dstsize)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	if (dest_len < dstsize)
		return (dest_len + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}
