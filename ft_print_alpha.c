/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 07:15:53 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/01 11:53:04 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string(t_printf *data)
{
	char	*string;

	string = va_arg(data->arguments, char *);
	if (!string)
		string = "(null)";
	ft_putstr_fd(string, 1);
	data->total_length += ft_strlen(string);
}

static void	ft_print_char(t_printf *data)
{
	int	c;

	c = va_arg(data->arguments, int);
	ft_putchar_fd(c, 1);
	data->total_length++;
}

void	ft_print_alpha(t_printf *data, const char *form)
{
	if (form[data->i] == 'c')
		ft_print_char(data);
	else if (form[data->i] == 's')
		ft_print_string(data);
}
