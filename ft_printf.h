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

# define TRUE	1;
# define FALSE	0;

int								g_return;

typedef struct s_flags			t_flags;
typedef struct s_specification	t_specification;
typedef int						t_bool;

struct		s_flags
{
	t_bool	minus;
	t_bool	plus;
	t_bool	space;
	t_bool	hash;
	t_bool	zero;
};

struct		s_specification
{
	t_flags	flags;
	int		width;
	int		precision;
	char	*modifier;
	char	type;
};

int			ft_printf(const char *format, ...);
int			length_of_number(int nbr);

#endif
