/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:42:21 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/28 04:13:49 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

// arguments - The argument-List
// i - iterator;
// width - Width (e.g. 3d)
// precision - Precision (e.g. .3d)
// zero - Flag '0'
// dash - Flag '-'
// plus - Flag '+'
// hash - Flag '#'
// space - Flag ' '
// total_length ft_printf (Return Value)

typedef struct s_printf
{
	va_list	arguments;
	int		i;
	int		width;
	int		precision;
	int		zero;
	int		dash;
	int		plus;
	int		hash;
	int		space;
	int		total_length;
}			t_printf;

typedef struct s_program
{
	char	converter;
	int		(*f)(t_printf *);
}			t_program;

int			ft_printf(const char *format, ...);
int			ft_parse(t_printf *data, const char *fmt);
int			ft_is_specifier(char c);

#endif
