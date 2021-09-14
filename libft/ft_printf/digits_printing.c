/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_printing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:23:42 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 16:57:41 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_d(t_struct *pf, va_list *ap)
{
	long int		num;

	num = (long)va_arg(*ap, int);
	if (num < 0)
	{
		pf->fl_sign = '-';
		num = -num;
	}
	print_number(num, pf, 10);
}

void	print_u(t_struct *pf, va_list *ap)
{
	uintmax_t		num;

	num = (unsigned int)va_arg(*ap, unsigned int);
	print_number(num, pf, 10);
}

void	print_p(t_struct *pf, va_list *ap)
{
	uintmax_t		num;

	num = (uintmax_t)va_arg(*ap, void *);
	pf->fl_hash = 1;
	print_number(num, pf, 16);
}

void	print_x(t_struct *pf, va_list *ap)
{
	uintmax_t		num;

	num = va_arg(*ap, unsigned int);
	if (pf->type == 'x')
		print_number(num, pf, 16);
	else if (pf->type == 'X')
		print_number(num, pf, 17);
}

/*
**	base 17 (in case of type X) indicates
**	that this is upper hexadecimal number
*/

void	print_ob(t_struct *pf, va_list *ap)
{
	uintmax_t		num;

	num = va_arg(*ap, unsigned int);
	if (pf->type == 'o')
		print_number(num, pf, 8);
	else if (pf->type == 'b')
		print_number(num, pf, 2);
}
