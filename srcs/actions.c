/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:49:35 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 11:49:37 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_big_sort(t_stack **lst_head_A, t_stack **lst_head_B, int lst_size)
{
	int		i;
	int		n;
	int		max_bits;

	i = 0;
	max_bits = ps_get_max_bits(lst_size);
	while (i < max_bits)
	{
		n = 0;
		while (n < lst_size)
		{
			if ((*lst_head_A)->index & (1 << i))
				ps_ra_rb(lst_head_A, "ra\n");
			else
				ps_pa_pb(lst_head_A, lst_head_B, "pb\n");
			n++;
		}
		while (*lst_head_B)
			ps_pa_pb(lst_head_B, lst_head_A, "pa\n");
		i++;
	}
}

void	ps_three_sort(t_stack **head)
{
	while (!(ps_is_sorted(*head)))
	{
		if (((*head)->index < (*head)->next->next->index
				&& (*head)->next->index > (*head)->next->next->index)
			|| ((*head)->index < (*head)->next->next->index
				&& (*head)->next->index < (*head)->index)
			|| ((*head)->index > (*head)->next->index
				&& (*head)->next->index > (*head)->next->next->index))
			ps_sa_sb(head, "sa\n");
		else if ((*head)->index > (*head)->next->next->index
			&& (*head)->next->index < (*head)->next->next->index)
			ps_ra_rb(head, "ra\n");
		else if ((*head)->index < (*head)->next->index
			&& (*head)->next->index > (*head)->index)
			ps_rra_rrb(head, 3, "rra\n");
	}
}

static void	ps_if_high_number(t_stack **head_A, t_stack **head_B,
		int *size_B, int size)
{
	t_stack	*last;
	t_stack	*first;

	first = (*head_A);
	last = ps_go_to_last_elem(*head_A);
	while ((*size_B) > 0)
	{
		while ((*head_B) && (!(((*head_B)->index > last->index)
					&& (((*head_B)->index < (*head_A)->index)
						|| (*head_A) == first))))
		{
			ps_rra_rrb(head_A, size - (*size_B), "rra\n");
			last = ps_go_to_last_elem(*head_A);
		}
		ps_pa_pb(head_B, head_A, "pa\n");
		(*size_B)--;
		if (!((*head_B) && (((*head_B)->index > last->index)
					&& (((*head_B)->index < (*head_A)->index)
						|| (*head_A) == first))))
			break ;
	}
	while (!(ps_is_sorted(*head_A)))
		ps_ra_rb(head_A, "ra\n");
}

void	ps_five_sort(t_stack **head_A, t_stack **head_B, int size)
{
	int	size_B;

	size_B = 1;
	ps_pa_pb(head_A, head_B, "pb\n");
	if (size == 5 && !(ps_is_sorted(*head_A)))
	{
		ps_pa_pb(head_A, head_B, "pb\n");
		size_B = 2;
	}
	if (!(ps_is_sorted(*head_A)))
		ps_three_sort(head_A);
	if ((*head_B)->index > 1 && (*head_B)->next && (*head_B)->next->index == 0)
		ps_sa_sb(head_B, "sb\n");
	while (*head_B)
	{
		if ((*head_B)->index == 0 || (*head_B)->index == 1)
		{
			ps_pa_pb(head_B, head_A, "pa\n");
			size_B--;
			if (!(ps_is_sorted(*head_A)))
				ps_sa_sb(head_A, "sa\n");
		}
		else
			ps_if_high_number(head_A, head_B, &size_B, size);
	}
}

int	ps_get_max_bits(int lst_size)
{
	int	max_num;
	int	max_bits;

	max_num = lst_size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
