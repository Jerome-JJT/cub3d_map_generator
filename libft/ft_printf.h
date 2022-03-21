/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaqueme <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:15:30 by jjaqueme          #+#    #+#             */
/*   Updated: 2021/10/21 15:28:03 by jjaqueme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

# include <stdio.h>

typedef struct s_pad {
	int	pad;
	int	preci;
}	t_pad;

typedef struct s_param {
	char	type;
	char	*raw;
	int		input_width;
	int		pad_width;
	int		precision;

	int		after;
	int		zeroed;
	int		plused;
	int		spaced;
	int		prefixed;
	int		precise;
}	t_param;

typedef union u_pdata {
	int				i;
	unsigned int	u;
	void			*p;
}	t_pdata;

void			ft_init_param(t_param **param);
void			ft_read_params(t_param **param, int *i);
void			ft_store_param(t_param **param, char *raw, int *i);
void			ft_store_arg(char type, va_list ap, t_pdata **data);
int				ft_is_endparam(char c);

unsigned long	ft_ulong_pow(int nb, int power);
int				ft_miniatoi(char *s, int *i);
int				ft_nb_len(int n);
int				ft_nb_len_u(unsigned int n);
int				ft_nb_len_h(unsigned long n);

void			ft_myputchar_fd(char c, int fd, int *written);
void			ft_myputstr_fd(char *s, int n, int fd, int *written);
void			ft_putsint_fd(int nb, int fd, int *written);
void			ft_putuint_fd(unsigned int nb, int fd, int *written);
void			ft_puthexa_fd(unsigned long nb, int capslock,
					int fd, int *written);

void			ft_print_all(t_param **param, t_pdata *data, char type,
					int *written);
void			ft_print_prefix(t_param **param, t_pdata *data, t_pad *to,
					int *written);
void			ft_print_sign(t_param **param, t_pdata *data,
					int *written);
void			ft_print_data(t_param **param, t_pdata *data, char type,
					int *written);
void			ft_print_suffix(t_param **param, int to_pad, int *written);

void			ft_mult_print_fd(char c, int n, int fd, int *written);
void			ft_evaluate_size(t_param **param, char type, t_pdata *data);
int				ft_printf(const char *format, ...);

#endif
