/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:36 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/28 04:12:37 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_flag(const char *fmt)
{
	if (*fmt == '0' || *fmt == '-' || *fmt == '+'
		|| *fmt == '#' || *fmt == ' ')
		return (1);
	return (0);
}

static int	ft_parse_flags(t_printf *data, const char *fmt)
{
}

static int	ft_parse_width(t_printf *data, const char *fmt)
{
}

static int	ft_parse_precision(t_printf *data, const char *fmt)
{
}

int	ft_parse(t_printf *data, const char *fmt)
{
	int	start_pos;

	start_pos = data->i;
	data->i++;
	while (fmt[data->i])
	{
		if (ft_is_flag(&fmt[data->i]))
			ft_parse_flags(data, fmt);
		else if (ft_isdigit(fmt[data->i]))
			ft_parse_width(data, &fmt[data->i]);
		else if (fmt[data->i] == '.')
			ft_parse_precision(data, &fmt[data->i]);
	}
	if (ft_is_specifier(fmt[data->i]))
		ft_dispatch(data, fmt[data->i]);

}