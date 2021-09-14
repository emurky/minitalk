/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:11:47 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:47:40 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(n / 10 * sign, fd);
		ft_putnbr_fd(n % 10 * sign, fd);
	}
	else
		ft_putchar_fd(n * sign + '0', fd);
}
