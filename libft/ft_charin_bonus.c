/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charin_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 21:17:06 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:35:54 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_charin(char c, const char *str)
{
	int		i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(str) + 1;
	while (slen--)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
