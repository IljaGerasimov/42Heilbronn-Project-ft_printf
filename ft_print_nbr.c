/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 00:43:10 by igerasim          #+#    #+#             */
/*   Updated: 2025/12/01 11:48:58 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int u)
{
	int	count;

	count = 0;
	if (u >= 10)
		count += ft_unsigned_len(u / 10);
	ft_putchar_fd((u % 10) + '0', 1);
	return (count + 1);
}

static void	ft_print_unsigneddec(t_printf *data)
{
	unsigned int	u;

	u = va_arg(data->arguments, unsigned int);
	data->total_length += ft_unsigned_len(u);
}

static void	ft_print_integer(t_printf *data)
{
	char	*integer;

	integer = ft_itoa(va_arg(data->arguments, int));
	ft_putstr_fd(integer, 1);
	data->total_length += ft_strlen(integer);
	free(integer);
}

void	ft_print_nbr(t_printf *data, const char *form)
{
	if (form[data->i] == 'u')
		ft_print_unsigneddec(data);
	if (form[data->i] == 'd' || form[data->i] == 'i')
		ft_print_integer(data);
}
