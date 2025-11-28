/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:33:28 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/28 04:16:02 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initialise_data(t_printf *data)
{
	data->width = 0;
	data->precision = -1;
	data->zero = 0;
	data->dash = 0;
	data->plus = 0;
	data->hash = 0;
	data->space = 0;
}

int	ft_printf(const char *format, ...)
{
	t_printf	data;

	if (!format)
		return (-1);
	ft_initialise_data(&data);
	va_start((data.arguments), format);
	data.total_length = 0;
	data.i = 0;
	while (format[data.i])
	{
		if (format[data.i] == '%')
		{
			ft_initialise_data(&data);
			data.i += ft_parse(&data, format);
		}
		else
		{
			write(1, (char *)&format[data.i], 1);
			data.total_length++;
			data.i++;
		}
	}
	va_end(data.arguments);
	return (data.total_length);
}

//("hallo %1.618d aka Aleph :)", int a, char *ohio)