/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:27:55 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:14:29 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	size;

	size = get_size(n);
	ptr = ft_calloc(size + 1, 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
		*ptr = '-';
	while ((size > 0 && *ptr != '-') || size > 1)
	{
		if (n < 0)
			*(ptr + --size) = -(n % -10) + '0';
		else
			*(ptr + --size) = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
