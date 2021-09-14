/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 02:25:49 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:48:58 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	char	*joinptr;
	size_t	len;

	if (!(s1 && s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = malloc(sizeof(char) * (len + 1));
	if (!joined_str)
		return (NULL);
	joinptr = joined_str;
	while (*s1)
		*joinptr++ = *s1++;
	while (*s2)
		*joinptr++ = *s2++;
	*joinptr = '\0';
	return (joined_str);
}
