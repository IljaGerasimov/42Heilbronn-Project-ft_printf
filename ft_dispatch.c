/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 04:08:11 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/01 11:53:05 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dispatch(t_printf *data, const char *form)
{
	data->i++;
	if (ft_strchr("cspdiuxX%", form[data->i]))
	{
		if (form[data->i] == 'c' || form[data->i] == 's')
			ft_print_alpha(data, form);
		if (form[data->i] == 'd' || form[data->i] == 'i'
			|| form[data->i] == 'u')
			ft_print_nbr(data, form);
		if (form[data->i] == 'p' || form[data->i] == 'x'
			|| form[data->i] == 'X')
			ft_print_hex(data, form);
		if (form[data->i] == '%')
		{
			write(1, "%", 1);
			data->total_length++;
		}
	}
}
