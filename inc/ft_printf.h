/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:00:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/31 15:23:47 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

# define BIN	2
# define OCT	8
# define DEC	10
# define HEX	16

int				g_return;

typedef struct s_specification	t_specification;
typedef struct s_flag			t_flag;

/*
** '#' - hash
** '0' - zero
** '-' - minus
** '+' - plus
** ' ' - space
**
** z > j > ll > l > h > hh
**
** sSpdDioOuUxXcC
*/
struct			s_flag
{
	bool		hash;
	bool		zero;
	bool		minus;
	bool		plus;
	bool		space;
};

struct			s_specification
{
	t_flag		flags;
	int			width;
	int			precision;
	char		*modifier;
	char		type;
};

int				ft_printf(const char *format, ...);
char			*get_replacing_specification(const char *format);

void			parse_print(char *replacing_spec, va_list ap);
t_specification	get_specification(char *replacing_spec, va_list ap,
																void **data);
void			print_data(void *data, t_specification spec);

void			s_lower_case(char *str, t_specification spec);
void			s_upper_case(unsigned int *str, t_specification spec);
void			p_lower_case(unsigned long long ptr, t_specification spec);
void			c_lower_case(char chr, t_specification spec);
void			c_upper_case(unsigned int chr, t_specification spec);

void			dec_long_long(long long nbr, t_specification spec);
void			dec_unsigned_long_long(unsigned long long nbr,
														t_specification spec);
void			bin_unsigned_long_long(unsigned long long nbr,
														t_specification spec);
void			oct_unsigned_long_long(unsigned long long nbr,
														t_specification spec);
void			hex_unsigned_long_long(unsigned long long nbr,
														t_specification spec);

void			di_with_len(void *data, t_specification spec);
void			o_with_len(void *data, t_specification spec);
void			u_with_len(void *data, t_specification spec);
void			x_with_len(void *data, t_specification spec);
void			b_with_len(void *data, t_specification spec);

#endif
