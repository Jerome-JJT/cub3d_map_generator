/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:51 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/18 18:17:14 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_split(const char *s, char c, char ***ptr)
{
	int	nb;
	int	keep;
	int	i;

	nb = 0;
	keep = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (keep == 0 && s[i] != c)
			keep = 1;
		else if ((keep == 1 && s[i] == c) || (c == '\0' && s[i + 1] == '\0'))
		{
			keep = 0;
			nb++;
		}
		i++;
	}
	*ptr = malloc(sizeof(char *) * (nb + keep + 1));
	if (*ptr == NULL)
		return (0);
	(*ptr)[nb + keep] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	i;
	int		j;
	int		nb;

	if (s == NULL || !ft_count_split(s, c, &ptr))
		return (NULL);
	i = 0;
	nb = 0;
	while (i < ft_strlen(s))
	{
		j = 0;
		while (s[i + j] != '\0' && s[i + j] != c)
			j++;
		if (j > 0)
		{
			ptr[nb] = ft_substr(s, i, j);
			nb++;
			i += j;
		}
		i++;
	}
	return (ptr);
}
