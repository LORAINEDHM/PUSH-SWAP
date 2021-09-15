/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:54:53 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:35:54 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	if (f == NULL || s == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
