/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:50:10 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:50:11 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra_rb(t_stack **head, char *str)
{
	t_stack	*to_move;

	if ((*head) && (*head)->next)
	{
		to_move = *head;
		*head = (*head)->next;
		ps_lstadd_back(head, to_move);
	}
	if (str)
		write(1, str, ft_strlen(str));
}

void	ps_rr(t_stack **head_A, t_stack **head_B, char *str)
{
	ps_ra_rb(head_A, NULL);
	ps_ra_rb(head_B, NULL);
	if (str)
		write(1, str, ft_strlen(str));
}
