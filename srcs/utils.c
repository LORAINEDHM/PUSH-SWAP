/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:50:31 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 15:28:14 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_go_to_last_elem(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

int	ps_is_sorted(t_stack *head)
{
	int	n;

	n = 0;
	while (head)
	{
		if (head->next)
		{
			if (head->index > head->next->index)
				return (0);
		}
		head = head->next;
	}
	return (1);
}

int	ps_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}
