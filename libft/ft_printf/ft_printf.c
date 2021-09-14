/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:32:05 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 16:56:32 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	struct_initialization(t_struct *pf)
{
	pf->fl_left = 0;
	pf->fl_zero = ' ';
	pf->fl_hash = 0;
	pf->fl_sign = 0;
	pf->width = 0;
	pf->precision = -1;
	pf->type = '\0';
}

/*
**	pf - struct for parsing format conversion specifications
*/

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	pf;
	char		*fmt;

	pf.chars_printed = 0;
	va_start(ap, format);
	fmt = (char *)format;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (!specs_parser(&pf, &fmt, &ap))
			{
				va_end(ap);
				return (-1);
			}
		}
		else
		{
			ft_putchar_fd(*fmt++, FD);
			pf.chars_printed++;
		}
	}
	va_end(ap);
	return (pf.chars_printed);
}
