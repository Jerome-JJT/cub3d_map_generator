/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:30:40 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/21 15:30:40 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_mult_print_fd(char c, int n, int fd, int *written)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_myputchar_fd(c, fd, written);
		i++;
	}
}

void	ft_evaluate_size(t_param **param, char type, t_pdata *data)
{
	if (type == 'c' || type == '%')
		(*param)->input_width = 1;
	else if (type == 'd' || type == 'i')
		(*param)->input_width = ft_nb_len(data->i);
	else if (type == 'u')
		(*param)->input_width = ft_nb_len_u(data->u);
	else if (type == 'x' || type == 'X')
		(*param)->input_width = ft_nb_len_h(data->u);
	else if (type == 's')
	{
		if ((char *)data->p != NULL)
			(*param)->input_width = ft_strlen((char *)data->p);
		else
			(*param)->input_width = 0;
	}
	else if (type == 'p')
	{
		(*param)->input_width = ft_nb_len_h((unsigned long)(data->p)) + 2;
	}
}

void	ft_process_argument(va_list ap, const char *format,
				int *i, int *written)
{
	t_param	*param;
	t_pdata	*data;
	int		j;

	param = malloc(sizeof(t_param));
	data = malloc(sizeof(t_pdata));
	if (param == NULL || data == NULL)
		return ;
	j = 0;
	while (!ft_is_endparam(format[*i + j]))
		j++;
	param->raw = ft_substr(format, *i, j);
	param->type = format[*i + j];
	ft_read_params(&param, i);
	ft_store_arg(param->type, ap, &data);
	ft_evaluate_size(&param, param->type, data);
	ft_print_all(&param, data, param->type, written);
	(*i)++;
	free((*param).raw);
	free(param);
	free(data);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		written;

	va_start(ap, format);
	written = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_myputchar_fd(format[i], 1, &written);
			i++;
		}
		else
		{
			i++;
			ft_process_argument(ap, format, &i, &written);
		}
	}
	va_end(ap);
	return (written);
}
