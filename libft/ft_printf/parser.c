/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 05:30:43 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:07:53 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_flags(t_struct *pf, char **fmt)
{
	while (**fmt == '#' || **fmt == '-' || **fmt == '0'
		|| **fmt == ' ' || **fmt == '+')
	{
		if (**fmt == '#')
			pf->fl_hash = 1;
		else if (**fmt == '-')
			pf->fl_left = 1;
		else if (**fmt == '0')
			pf->fl_zero = '0';
		else if (**fmt == '+')
			pf->fl_sign = '+';
		else if (**fmt == ' ')
			if (!pf->fl_sign)
				pf->fl_sign = ' ';
		(*fmt)++;
	}
}

void	parse_width(t_struct *pf, char **fmt, va_list *ap)
{
	if (**fmt == '*')
	{
		pf->width = va_arg(*ap, int);
		(*fmt)++;
		if (pf->width < 0)
		{
			pf->fl_left = 1;
			pf->width = -pf->width;
		}
	}
	else if (ft_isdigit(**fmt))
	{
		pf->width = ft_atoi(*fmt);
		(*fmt) += ft_nbrlen(pf->width);
	}
}

void	parse_precision(t_struct *pf, char **fmt, va_list *ap)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			pf->precision = va_arg(*ap, int);
			if (pf->precision < 0)
				pf->precision = -1;
			(*fmt)++;
		}
		else
		{
			pf->precision = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
		}
	}
}

int	types_processing(t_struct *pf, va_list *ap)
{
	if (pf->type == 'c')
		print_c(pf, ap);
	else if (pf->type == 's')
		print_s(pf, ap);
	else if (pf->type == 'p')
		print_p(pf, ap);
	else if (pf->type == 'd' || pf->type == 'i')
		print_d(pf, ap);
	else if (pf->type == 'u')
		print_u(pf, ap);
	else if (pf->type == 'x' || pf->type == 'X')
		print_x(pf, ap);
	else if (pf->type == 'o' || pf->type == 'b')
		print_ob(pf, ap);
	else if (pf->type == '%')
		print_c(pf, ap);
	else
		return (1);
	return (0);
}

int	specs_parser(t_struct *pf, char **fmt, va_list *ap)
{
	(*fmt)++;
	struct_initialization(pf);
	parse_flags(pf, fmt);
	parse_width(pf, fmt, ap);
	parse_precision(pf, fmt, ap);
	pf->type = **fmt;
	(*fmt)++;
	if (!types_processing(pf, ap))
		return (1);
	return (0);
}
