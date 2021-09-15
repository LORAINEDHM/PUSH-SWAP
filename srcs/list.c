/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:49:26 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:49:29 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*list;

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		return ;
	}
	if (stack && new)
	{
		list = *stack;
		while (list->next != NULL)
			list = list->next;
		list->next = new;
		new->next = NULL;
	}
}

void	ps_lstadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

int	ps_find_index(int *tab, int value, int size, int *index)
{
	int	i;

	i = 0;
	*index = 0;
	while (i < size)
	{
		if (tab[i] < value)
			(*index)++;
		i++;
	}
	return (0);
}

void	ps_create_list(int *tab, int *lst_size, t_stack **lst_head_A)
{
	t_stack	*elem;
	int		i;

	i = (*lst_size) - 1;
	while (i >= 0)
	{
		elem = ft_calloc(sizeof(t_stack), 1);
		if (!(elem))
			exit (0);
		elem->value = tab[i];
		ps_find_index(tab, elem->value, *lst_size, &elem->index);
		if (i == (*lst_size) - 1)
			(*lst_head_A) = elem;
		else
			ps_lstadd_front(lst_head_A, elem);
		i--;
	}
}
