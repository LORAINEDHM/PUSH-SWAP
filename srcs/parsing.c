/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:49:50 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/15 16:42:09 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_check_if_double(int i, int *tab)
{
	int	j;

	j = 0;
	while (i > 0 && j < i)
	{
		if (tab[i] == tab[j])
		{
			write(1, "Error\n", ft_strlen("Error\n"));
			return (1);
		}
		j++;
	}
	return (0);
}

static int	ps_check_char_validity(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
	{
		write(1, "Error\n", ft_strlen("Error\n"));
		return (0);
	}
	while (str[i] != 0)
	{
		if (!(ft_isdigit(str[i])))
		{
			write(1, "Error\n", ft_strlen("Error\n"));
			return (0);
		}
		i++;
	}
	return (1);
}

int	*ps_is_valid(int lst_size, char **str_tab)
{
	int	*tab;
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	tab = malloc(sizeof(int) * lst_size);
	if (!(tab))
		exit (0);
	while (str_tab[i])
	{
		if (!(ps_check_char_validity(str_tab[i])))
			exit (0);
		if (str_tab[i][0] == '-')
			neg = 1;
		if ((int)ft_strlen(str_tab[i]) > 10 + neg)
			handle_error("Error\n");
		tab[i] = ft_atoi(str_tab[i]);
		if ((tab[i] < 0 && neg == 0) || (tab[i] > 0 && neg == 1))
			handle_error("Error\n");
		if (ps_check_if_double(i, tab) == 1)
			exit (0);
		i++;
	}
	return (tab);
}

int	*ps_parsing(int ac, char **av, int *lst_size)
{
	int		*tab;
	char	**str_tab;

	if (ac == 2)
	{
		str_tab = ft_split(av[1], ' ');
		if (!(str_tab[0]))
			handle_error("Error\n");
		*lst_size = ps_tab_size(str_tab);
	}
	else
	{
		str_tab = av + 1;
		*lst_size = ac - 1;
	}
	tab = ps_is_valid(*lst_size, str_tab);
	if (ac == 2)
		ps_free_and_init_dtab(str_tab, *lst_size);
	return (tab);
}
