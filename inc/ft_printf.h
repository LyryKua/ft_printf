/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:00:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/12/22 16:00:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>

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
t_specification	get_specification(char *replacing_spec);
void			print_data(void *data, t_specification spec);

#endif