/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:50:45 by jjaqueme          #+#    #+#             */
/*   Updated: 2022/01/18 20:14:38 by ahuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

unsigned long	ft_ulong_pow(int nb, int power)
{
	unsigned long	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

int	ft_miniatoi(char *s, int *i)
{
	int	res;

	res = s[*i] - '0';
	while (ft_isdigit(s[*i + 1]))
	{
		(*i)++;
		res = res * 10 + s[*i] - '0';
	}
	return (res);
}

int	ft_nb_len(int n)
{
	if (n < 10 && n >= 0)
		return (1);
	else if (n > -10 && n < 0)
		return (1);
	else
		return (ft_nb_len(n / 10) + 1);
}

int	ft_nb_len_u(unsigned int n)
{
	if (n < 10)
		return (1);
	else
		return (ft_nb_len_u(n / 10) + 1);
}

int	ft_nb_len_h(unsigned long n)
{
	if (n < 16)
		return (1);
	else
		return (ft_nb_len_h(n / 16) + 1);
}
