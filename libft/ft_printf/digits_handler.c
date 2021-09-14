/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:41:03 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 16:57:26 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	prefix_handler(char *prefix, uintmax_t num, t_struct *pf, int base)
{
	int				prefix_len;

	ft_bzero(prefix, sizeof(prefix));
	if (pf->fl_sign)
		if (base == 10)
			prefix[0] = pf->fl_sign;
	if ((num && pf->fl_hash) || pf->type == 'p')
	{
		if (base == 16)
			ft_memcpy(prefix, "0x", 3);
		else if (base == 17)
			ft_memcpy(prefix, "0X", 3);
		else if (base == 8)
			prefix[0] = '0';
		else if (base == 2)
			ft_memcpy(prefix, "0b", 3);
	}
	prefix_len = ft_strlen(prefix);
	return (prefix_len);
}

void	ft_itoa_base(char **pbuf, uintmax_t num, t_struct *pf, int base)
{
	char			*hexdigits;

	if (base == 17)
	{
		hexdigits = "0123456789ABCDEF";
		base--;
	}
	else
		hexdigits = "0123456789abcdef";
	if (num == 0 && pf->precision)
		*(*pbuf)-- = '0';
	else
	{
		while (num)
		{
			*(*pbuf)-- = hexdigits[num % base];
			num /= base;
		}
	}
}

void	specs_handler(t_struct *pf, char *prefix, int *num_len)
{
	int				prefix_len;

	prefix_len = ft_strlen(prefix);
	pf->width -= prefix_len;
	if (pf->fl_zero == '0')
		ft_putstr_fd(prefix, FD);
	if (!pf->fl_left)
		while (pf->width > *num_len && pf->width-- > pf->precision)
			ft_putchar_fd(pf->fl_zero, FD);
	if (pf->fl_zero == ' ')
		ft_putstr_fd(prefix, FD);
	while (pf->precision-- > *num_len)
	{
		ft_putchar_fd('0', FD);
		pf->width--;
	}
}

void	print_number(uintmax_t num, t_struct *pf, int base)
{
	char			buf[BUFFER];
	char			*pbuf;
	char			prefix[3];
	int				num_len;
	int				prefix_len;

	prefix_len = prefix_handler((char *)prefix, num, pf, base);
	pbuf = &buf[BUFFER - 1];
	ft_itoa_base(&pbuf, num, pf, base);
	if (pf->precision < 0)
		pf->precision = 1;
	else
		pf->fl_zero = ' ';
	num_len = &buf[BUFFER - 1] - pbuf;
	pf->chars_printed += get_max(pf->width,
			get_max(num_len, pf->precision) + prefix_len);
	specs_handler(pf, prefix, &num_len);
	while (++pbuf != &buf[BUFFER])
		ft_putchar_fd(*pbuf, FD);
	if (pf->fl_left)
		while (pf->width-- > num_len)
			ft_putchar_fd(' ', FD);
}
