/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:27:09 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 15:27:22 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_list(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	ps_free_and_init_dtab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}

void	ms_free_list(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		if (*stack)
		{
			temp = (*stack)->next;
			free(*stack);
			*stack = temp;
		}
	}
}
