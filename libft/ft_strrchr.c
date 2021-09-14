/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:23:36 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:50:20 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	offset;

	offset = ft_strlen(s) + 1;
	while (offset--)
		if (*(s + offset) == (char)c)
			return ((char *)s + offset);
	return (NULL);
}
