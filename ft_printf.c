/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 07:33:28 by igerasim          #+#    #+#             */
/*   Updated: 2025/11/17 18:48:12 by igerasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// #include <stdio.h>

int	ft_printf(const char *format, ...)
{
	t_list2	args;

	va_start((args.my_arguments), format);
	if (!*format)
		return (NULL);
	args.total_written = 0;
	while (*format)
	{
		while (*format == '%')
		{
			format++;
			ft_parse(*format++, &args);
		}
		write(1, format++, 1);
		args.total_written++;
	}
	return (ft_strlen(format));
}

// int	main(void)
// {
// 	char	a[] = "abc";

// 	printf("%s abadwa", a);
// 	return (0);
// }
