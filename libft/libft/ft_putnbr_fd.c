/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:39:51 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/14 12:39:51 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	pow;
	int	flag;
	int	temp;
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = sign * -1;
	}
	flag = 0;
	pow = 9;
	while (pow >= 0)
	{
		temp = sign * ((n / ft_pow(10, pow)) % 10) + '0';
		if (flag || pow == 0 || temp != '0')
		{
			flag = 1;
			ft_putchar_fd(temp, fd);
		}
		pow--;
	}
}
