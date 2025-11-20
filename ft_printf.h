/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:42:21 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/16 20:54:26 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_list2
{
	va_list			my_arguments;
	unsigned int	total_written;
}					t_list2;

int					ft_printf(const char *format, ...);
int					ft_parse(const char *format, ...);

#endif