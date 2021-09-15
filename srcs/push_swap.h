/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:20:23 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 16:39:52 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include "libft.h"
# include <limits.h>
# include <errno.h>
# include <unistd.h>

/*
** ------------------------- Structure Definitions -----------------------------
*/

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}				t_stack;

/*
** ------------------------- Enum Definitions ----------------------------------
*/

typedef enum e_error
{
	INVALID_NUMBER,
	DOUBLE_NUMBER,
}				t_elem_error;

/*
** -----------------------------------------------------------------------------
** ------------------------------- Sources -------------------------------------
** -----------------------------------------------------------------------------
*/

/*
** ---------------------------------- main.c -----------------------------------
*/
int		main(int ac, char **av);
void	handle_error(char *str);

/*
** ---------------------------------- parsing.c --------------------------------
*/

int		*ps_parsing(int ac, char **av, int *lst_size);
int		*ps_is_valid(int lst_size, char **str_tab);

/*
** ---------------------------------- list.c -----------------------------------
*/

void	ps_create_list(int *tab, int *lst_size, t_stack **lst_head_A);
void	ps_lstadd_front(t_stack **stack, t_stack *new);
void	ps_lstadd_back(t_stack **stack, t_stack *new);

/*
** ---------------------------------- sa_sb_ss.c --------------------------------
*/

void	ps_sa_sb(t_stack **head, char *str);
void	ps_ss(t_stack **head_A, t_stack **head_B, char *str);

/*
** ---------------------------------- pa_pb.c ----------------------------------
*/

void	ps_pa_pb(t_stack **head_A, t_stack **head_B, char *pa_or_pb);

/*
** ---------------------------------- ra_rb_rr.c -------------------------------
*/

void	ps_ra_rb(t_stack **head, char *str);
void	ps_rr(t_stack **head_A, t_stack **head_B, char *str);

/*
** ---------------------------------- rra.c -----------------------------------
*/

void	ps_rra_rrb(t_stack **head, int size, char *str);
void	ps_rrr(t_stack **head_A, t_stack **head_B, int size, char *str);

/*
** ---------------------------------- actions.c ---------------------------------
*/

void	ps_big_sort(t_stack **lst_head_A, t_stack **lst_head_B, int lst_size);
void	ps_three_sort(t_stack **head);
void	ps_five_sort(t_stack **head_A, t_stack **head_B, int size);
int		ps_get_max_bits(int lst_size);

/*
** ---------------------------------- utils.c -----------------------------------
*/

int		ps_tab_size(char **tab);
t_stack	*ps_go_to_last_elem(t_stack *head);
int		ps_is_sorted(t_stack *head);

/*
** ---------------------------------- free.c ------------------------------------
*/

void	ps_free_list(t_stack **stack);
void	ps_free_and_init_dtab(char **tab, int n);
void	ms_free_list(t_stack **stack);

#endif