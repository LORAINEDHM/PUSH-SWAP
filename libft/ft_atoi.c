/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:26 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 14:47:43 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;
	unsigned long	limit;

	result = 0;
	limit = __LONG_MAX__ / 10;
	sign = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*str))
	{
		if ((result == limit && (*str - '0') > 6 - sign) || result > limit)
			return (-sign - 1);
		result = result * 10 + *str++ - '0';
	}
	if (sign)
		return (result * sign);
	return (result);
}
