/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:00:36 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/28 08:06:39 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_flag(const char *form)
{
	if (*form == '0' || *form == '-' || *form == '+'
		|| *form == '#' || *form == ' ')
		return (1);
	return (0);
}

static int	ft_parse_flags(t_printf *data, const char *form)
{
}

static int	ft_parse_width(t_printf *data, const char *form)
{
}

static int	ft_parse_precision(t_printf *data, const char *form)
{
}

int	ft_parse(t_printf *data, const char *form)
{
	int	start_pos;

	start_pos = data->i;
	data->i++;
	while (!(ft_isalpha(form[data->i])))
	{
		if (ft_is_flag(&form[data->i]))
			ft_parse_flags(data, form);
		else if (ft_isdigit(form[data->i]) || form[data->i] == '*')
			ft_parse_width(data, &form[data->i]);
		else if (form[data->i] == '.')
			ft_parse_precision(data, &form[data->i]);
		data->i++;
	}
	if (ft_strchr("cspdiuxX%", form[data->i]))
		ft_dispatch(data, form[data->i]);
	return (start_pos);
}
