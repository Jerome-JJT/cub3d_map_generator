/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:57:39 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/21 12:57:39 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_myputchar_fd(char c, int fd, int *written)
{
	write(fd, &c, 1);
	(*written)++;
}

void	ft_myputstr_fd(char *s, int n, int fd, int *written)
{
	if (s == NULL)
		return ;
	write(fd, s, n);
	(*written) += n;
}

void	ft_putsint_fd(int nb, int fd, int *written)
{
	int	pow;
	int	flag;
	int	temp;
	int	sign;

	sign = 1;
	if (nb < 0)
	{
		sign = sign * -1;
	}
	flag = 0;
	pow = 9;
	while (pow >= 0)
	{
		temp = sign * ((nb / ft_pow(10, pow)) % 10) + '0';
		if (flag || pow == 0 || temp != '0')
		{
			flag = 1;
			ft_myputchar_fd(temp, fd, written);
		}
		pow--;
	}
}

void	ft_putuint_fd(unsigned int nb, int fd, int *written)
{
	int	pow;
	int	flag;
	int	temp;

	flag = 0;
	pow = 9;
	while (pow >= 0)
	{
		temp = ((nb / ft_pow(10, pow)) % 10) + '0';
		if (flag || pow == 0 || temp != '0')
		{
			flag = 1;
			ft_myputchar_fd(temp, fd, written);
		}
		pow--;
	}
}

void	ft_puthexa_fd(unsigned long nb, int capslock, int fd, int *written)
{
	int		pow;
	int		flag;
	int		temp;
	char	*hexa;

	if (capslock)
		hexa = ft_strdup("0123456789ABCDEF");
	else
		hexa = ft_strdup("0123456789abcdef");
	flag = 0;
	pow = 15;
	while (pow >= 0)
	{
		temp = (nb / ft_ulong_pow(16, pow)) % 16;
		if (flag || pow == 0 || temp != 0)
		{
			flag = 1;
			ft_myputchar_fd(hexa[temp], fd, written);
		}
		pow--;
	}
	free(hexa);
}
