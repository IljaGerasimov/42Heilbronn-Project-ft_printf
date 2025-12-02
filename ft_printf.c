/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:33:28 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/02 10:10:16 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	t_printf	data;

	if (!form)
		return (-1);
	va_start((data.arguments), form);
	data.total_length = 0;
	data.i = 0;
	while (form[data.i])
	{
		if (form[data.i] == '%')
		{
			ft_dispatch(&data, form);
			data.i++;
		}
		else
		{
			write(1, (char *)&form[data.i], 1);
			data.total_length++;
			data.i++;
		}
	}
	va_end(data.arguments);
	return (data.total_length);
}
