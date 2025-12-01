/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:42:21 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/01 11:48:51 by igerasim         ###   ########.fr       */
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
	int		total_length;
}			t_printf;

/// @brief Scans String for Specifiers and prints Arguments
/// @return length of total printed characters
int			ft_printf(const char *form, ...);
void		ft_dispatch(t_printf *data, const char *form);
void		ft_print_alpha(t_printf *data, const char *form);
void		ft_print_nbr(t_printf *data, const char *form);
void		ft_print_hex(t_printf *data, const char *form);

#endif
