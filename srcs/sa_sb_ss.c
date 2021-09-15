/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:50:25 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:50:27 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa_sb(t_stack **head, char *str)
{
	t_stack	*temp;
	t_stack	*new;

	new = ft_calloc(sizeof(t_stack), 1);
	if (!new)
		exit (0);
	if (*head && (*head)->next)
	{
		new->index = (*head)->next->index;
		new->value = (*head)->next->value;
		temp = (*head)->next;
		(*head)->next = (*head)->next->next;
		new->next = (*head);
		free(temp);
		(*head) = new;
	}
	if (str)
		write(1, str, ft_strlen(str));
}

void	ps_ss(t_stack **head_A, t_stack **head_B, char *str)
{
	ps_sa_sb(head_A, NULL);
	ps_sa_sb(head_B, NULL);
	if (str)
		write(1, "ss\n", ft_strlen("ss\n"));
}
