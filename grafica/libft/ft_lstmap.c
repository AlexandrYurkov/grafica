/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:14:47 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/08 15:15:41 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*elem;
	t_list	*l;

	if (!(lst) || !(*f))
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!(new))
		return (NULL);
	l = new;
	lst = lst->next;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!(elem))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		l->next = elem;
		l = elem;
		lst = lst->next;
	}
	return (new);
}
