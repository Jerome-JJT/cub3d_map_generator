/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:49 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:49 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_nb_length(int n, int sign)
{
	int	pow;

	pow = 9;
	while (pow > 0)
	{
		if (sign == 1 && n >= ft_pow(10, pow))
		{
			return (pow + 1);
		}
		else if (sign == -1 && n <= ft_pow(10, pow) * -1)
		{
			return (pow + 2);
		}
		pow--;
	}
	if (sign == 1)
		return (1);
	else
		return (2);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		nblen;
	int		i;

	sign = 1;
	if (n < 0)
		sign = sign * -1;
	nblen = ft_itoa_nb_length(n, sign);
	ptr = malloc(nblen + 1);
	if (ptr == NULL)
		return (NULL);
	i = nblen;
	ptr[i] = '\0';
	while (i > 0)
	{
		i--;
		if (i == 0 && sign == -1)
			ptr[i] = '-';
		else
			ptr[i] = (n % 10) * sign + '0';
		n /= 10;
	}
	return (ptr);
}
