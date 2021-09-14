/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:27:00 by emurky            #+#    #+#             */
/*   Updated: 2021/09/14 17:40:53 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**newlst;
	t_list	*ret;

	(void)del;
	if (!lst)
		return (NULL);
	newlst = &ret;
	*newlst = ft_lstnew(f(lst->content));
	while (lst->next)
	{
		lst = lst->next;
		newlst = &((*newlst)->next);
		*newlst = ft_lstnew(f(lst->content));
	}
	return (ret);
}
