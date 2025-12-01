/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:07:44 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/01 11:48:50 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long	ft_print_hexa(unsigned long hexa, char *lookup_tabel)
{
	int	count;

	count = 0;
	if (hexa >= 16)
		count += ft_print_hexa(hexa / 16, lookup_tabel);
	ft_putchar_fd(lookup_tabel[hexa % 16], 1);
	return (count + 1);
}

void	ft_print_hex(t_printf *data, const char *form)
{
	unsigned int	num;
	unsigned long	l_num;

	if (form[data->i] == 'x' || form[data->i] == 'X')
	{
		num = va_arg(data->arguments, unsigned int);
		if (num == 0)
			data->total_length += write(1, "0", 1);
		else if (form[data->i] == 'x')
			data->total_length += ft_print_hexa(num, "0123456789abcdef");
		else if (form[data->i] == 'X')
			data->total_length += ft_print_hexa(num, "0123456789ABCDEF");
	}
	else if (form[data->i] == 'p')
	{
		l_num = va_arg(data->arguments, unsigned long);
		if (l_num == 0)
			data->total_length += write(1, "(nil)", 5);
		else
		{
			data->total_length += write(1, "0x", 2);
			data->total_length += ft_print_hexa(l_num, "0123456789abcdef");
		}
	}
}
