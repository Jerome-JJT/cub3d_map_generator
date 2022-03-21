/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:09:18 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/21 12:09:18 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_init_param(t_param **param)
{
	(*param)->input_width = 0;
	(*param)->pad_width = 0;
	(*param)->after = 0;
	(*param)->zeroed = 0;
	(*param)->plused = 0;
	(*param)->spaced = 0;
	(*param)->prefixed = 0;
	(*param)->precise = 0;
	(*param)->precision = 0;
}

void	ft_read_params(t_param **param, int *i)
{
	int		j;

	j = 0;
	while ((*param)->raw[j] != '\0')
	{
		ft_store_param(param, (*param)->raw, &j);
		j++;
	}
	(*i) += j;
}

void	ft_store_param(t_param **param, char *raw, int *i)
{
	if (raw[*i] == '-')
		(*param)->after = 1;
	else if (raw[*i] == '0')
		(*param)->zeroed = 1;
	else if (raw[*i] == '+')
		(*param)->plused = 1;
	else if (raw[*i] == ' ')
		(*param)->spaced = 1;
	else if (raw[*i] == '#')
		(*param)->prefixed = 1;
	else if (raw[*i] >= '1' && raw[*i] <= '9')
		(*param)->pad_width = ft_miniatoi((*param)->raw, i);
	else if (raw[*i] == '.')
	{
		(*param)->precise = 1;
		if (raw[*i + 1] >= '0' && raw[*i + 1] <= '9')
		{
			(*i)++;
			(*param)->precision = ft_miniatoi((*param)->raw, i);
		}
	}
}

void	ft_store_arg(char type, va_list ap, t_pdata **data)
{
	if (type == 'c' || type == 'd' || type == 'i')
	{
		(*data)->i = va_arg(ap, int);
	}
	else if (type == 'u' || type == 'x' || type == 'X')
	{
		(*data)->u = va_arg(ap, unsigned int);
	}
	else if (type == 's' || type == 'p')
	{
		(*data)->p = va_arg(ap, void *);
	}
	else if (type == '%')
	{
		(*data)->i = '%';
	}
}

int	ft_is_endparam(char c)
{
	const char	set[] = "cspdiuxX%";

	return (ft_strchr(set, c) != NULL);
}
