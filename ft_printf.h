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

# define TRUE	1
# define FALSE	0

int								g_return;

typedef struct s_flags			t_flags;
typedef struct s_modifier		t_modifier;
typedef struct s_specification	t_specification;
typedef int						t_bool;

enum			e_priority
{
	ZERO,
	HH,
	H,
	L,
	LL,
	J,
	Z
};

struct			s_flags
{
	t_bool		minus;
	t_bool		plus;
	t_bool		space;
	t_bool		hash;
	t_bool		zero;
};

struct			s_modifier
{
	char		*value;
	int			priority;
};

/*
** z > j > ll > l > h > hh
**
** sSpdDioOuUxXcC
*/

struct			s_specification
{
	t_flags		flags;
	int			width;
	int			precision;
	t_modifier	modifier;
	char		type;
	int			step;
};

int				ft_printf(const char *format, ...);

void			fill_specification(const char *format, t_specification *spec);
void			fill_modifier(const char *modifier, t_specification *spec);

#endif
