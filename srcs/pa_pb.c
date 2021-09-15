/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:49:43 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:49:45 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_pa_pb(t_stack **head_A, t_stack **head_B, char *pa_or_pb)
{
	t_stack	*to_move;

	if (*head_A)
	{
		to_move = *head_A;
		*head_A = (*head_A)->next;
		ps_lstadd_front(head_B, to_move);
	}
	write(1, pa_or_pb, ft_strlen(pa_or_pb));
}
