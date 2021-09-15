/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:49:14 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 17:00:04 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(char *str)
{
	write(1, str, ft_strlen(str));
	exit (0);
}

static void	ps_sort_options(int lst_size, t_stack **head_A, t_stack **head_B)
{
	if (lst_size == 2)
	{
		if ((*head_A)->index > (*head_A)->next->index)
			ps_sa_sb(head_A, "sa\n");
	}
	else if (lst_size == 3)
		ps_three_sort(head_A);
	else if (lst_size <= 5)
		ps_five_sort(head_A, head_B, lst_size);
	else
		ps_big_sort(head_A, head_B, lst_size);
}

int	main(int ac, char **av)
{
	int		lst_size;
	t_stack	*lst_head_A;
	t_stack	*lst_head_B;
	int		*tab;

	lst_size = 0;
	lst_head_A = NULL;
	lst_head_B = NULL;
	if (ac < 2)
		return (0);
	else
	{
		tab = ps_parsing(ac, av, &lst_size);
		if (!tab)
			exit (0);
		if (lst_size == 1)
			exit (0);
		ps_create_list(tab, &lst_size, &lst_head_A);
		free(tab);
		if (!(ps_is_sorted(lst_head_A)))
			ps_sort_options(lst_size, &lst_head_A, &lst_head_B);
		ms_free_list(&lst_head_A);
	}
	exit (0);
}
