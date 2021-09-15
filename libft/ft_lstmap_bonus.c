/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:25:02 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:22:53 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	t_list	*lst2;

	if (lst && f && del)
	{
		lst2 = lst;
		head = ft_lstnew(f(lst2->content));
		if (!head)
			return (NULL);
		while (lst2->next)
		{
			lst2 = lst2->next;
			new = ft_lstnew(f(lst2->content));
			if (!new)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new);
		}
		return (head);
	}
	return (NULL);
}
