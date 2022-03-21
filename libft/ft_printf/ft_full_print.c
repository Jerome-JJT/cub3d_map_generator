/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:53:43 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/21 13:53:43 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_all(t_param **param, t_pdata *data, char type, int *written)
{
	t_pad	*to;

	to = malloc(sizeof(t_pad));
	to->preci = (*param)->precision - (*param)->input_width;
	if (to->preci < 0)
		to->preci = 0;
	if ((type == 'x' || type == 'X') && data->u > 0 && (*param)->prefixed == 1)
		(*param)->input_width += 2;
	else if ((*param)->plused && (type == 'd' || type == 'u' || type == 'i'))
	{
		if ((type == 'd' || type == 'i') && data->i > 0)
			(*param)->input_width += 1;
		else if (type == 'u' && data->u > 0)
			(*param)->input_width += 1;
	}
	to->pad = (*param)->pad_width - (to->preci + (*param)->input_width);
	if ((type == 'd' || type == 'i') && data->i < 0)
		to->pad -= 1;
	ft_print_prefix(param, data, to, written);
	ft_print_data(param, data, (*param)->type, written);
	ft_print_suffix(param, to->pad, written);
	free(to);
}

void	ft_print_prefix(t_param **param, t_pdata *data, t_pad *to, int *written)
{
	if ((*param)->after == 0)
	{
		if ((*param)->zeroed == 1 && (*param)->precise == 1 && to->pad > 0)
			ft_mult_print_fd(' ', to->pad, 1, written);
		else if ((*param)->zeroed == 0 && to->pad > 0)
			ft_mult_print_fd(' ', to->pad, 1, written);
	}
	ft_print_sign(param, data, written);
	if ((*param)->zeroed == 1 && (*param)->precise == 0
		&& (*param)->after == 0 && to->pad > 0)
	{
		ft_mult_print_fd('0', to->pad, 1, written);
	}
	if ((*param)->precise == 1 && (*param)->after == 0
		&& to->preci > 0 && (*param)->type != 's')
	{
		ft_mult_print_fd('0', to->preci, 1, written);
	}
}

void	ft_print_sign(t_param **param, t_pdata *data, int *written)
{
	char	type;

	type = (*param)->type;
	if (type == 'd' || type == 'i')
	{
		if (data->i >= 0 && (*param)->plused == 1)
			ft_myputchar_fd('+', 1, written);
		else if (data->i >= 0 && (*param)->spaced == 1)
			ft_myputchar_fd(' ', 1, written);
		else if (data->i < 0)
			ft_myputchar_fd('-', 1, written);
	}
	else if (type == 'u' && (*param)->plused == 1)
		ft_myputchar_fd('+', 1, written);
	else if ((*param)->prefixed == 1 && data->u > 0)
	{
		if (type == 'x')
			ft_myputstr_fd("0x", 2, 1, written);
		else if (type == 'X')
			ft_myputstr_fd("0X", 2, 1, written);
	}
	if (type == 'p')
		ft_myputstr_fd("0x", 2, 1, written);
}

void	ft_print_data(t_param **param, t_pdata *data, char type, int *written)
{
	if (type == 'c' || type == '%')
		ft_myputchar_fd(data->i, 1, written);
	else if (type == 'd' || type == 'i')
		ft_putsint_fd(data->i, 1, written);
	else if (type == 'u')
		ft_putuint_fd(data->u, 1, written);
	else if (type == 'x' || type == 'X')
		ft_puthexa_fd(data->u, type == 'X', 1, written);
	else if (type == 'p')
		ft_puthexa_fd((unsigned long)(data->p), 0, 1, written);
	else if (type == 's')
	{
		if (data->p != NULL)
		{
			if ((*param)->precise == 1
				&& (*param)->precision < (int)ft_strlen(data->p))
				ft_myputstr_fd(data->p, (*param)->precision, 1, written);
			else
				ft_myputstr_fd(data->p, ft_strlen(data->p), 1, written);
		}
		else
			ft_myputstr_fd("(null)", 6, 1, written);
	}
}

void	ft_print_suffix(t_param **param, int to_pad, int *written)
{
	if ((*param)->after == 1)
	{
		if ((*param)->zeroed == 1 && (*param)->precise == 1 && to_pad > 0)
			ft_mult_print_fd(' ', to_pad, 1, written);
		else if (to_pad > 0)
			ft_mult_print_fd(' ', to_pad, 1, written);
	}
}
