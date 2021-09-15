/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:50:18 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:50:19 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rra_rrb(t_stack **head, int size, char *str)
{
	t_stack	*new;
	t_stack	*head_temp;
	int		i;

	if (*head && (*head)->next)
	{
		if (size <= 2)
			ps_sa_sb(head, NULL);
		else
		{
			head_temp = *head;
			new = *head;
			i = 2;
			while (i < size)
			{
				new = new->next;
				i++;
			}
			(*head) = new->next;
			new->next = NULL;
			(*head)->next = head_temp;
		}
	}
	if (str)
		write(1, str, ft_strlen(str));
}

void	ps_rrr(t_stack **head_A, t_stack **head_B, int size, char *str)
{
	ps_rra_rrb(head_A, size, NULL);
	ps_rra_rrb(head_B, size, NULL);
	if (str)
		write(1, str, ft_strlen(str));
}
