/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:01:14 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 16:56:04 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	get_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

void	print_c(t_struct *pf, va_list *ap)
{
	char	c;

	pf->chars_printed += get_max(1, pf->width);
	if (pf->type == '%')
		c = '%';
	else
		c = va_arg(*ap, int);
	if (!(pf->fl_left))
		while ((pf->width)-- > 1)
			ft_putchar_fd(pf->fl_zero, FD);
	ft_putchar_fd(c, FD);
	while ((pf->width)-- > 1)
		ft_putchar_fd(' ', FD);
}

void	print_s(t_struct *pf, va_list *ap)
{
	char	*str;
	int		len;
	int		len_for_width;

	str = (char *)va_arg(*ap, void *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (pf->precision >= 0)
		len = get_min(len, pf->precision);
	pf->chars_printed += get_max(len, pf->width);
	if (!(pf->fl_left))
		while (pf->width && (pf->width)-- > len)
			ft_putchar_fd(pf->fl_zero, FD);
	len_for_width = len;
	while (*str && len--)
		ft_putchar_fd(*str++, FD);
	while ((pf->width)-- > len_for_width)
		ft_putchar_fd(' ', FD);
}
