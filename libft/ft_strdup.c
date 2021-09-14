/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 01:44:35 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:48:47 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*strdup;

	s2 = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	strdup = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (strdup);
}
