/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:01:44 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:34:53 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dst;
	unsigned int	i;
	int				j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dst = (char *)ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dst[i] = s2[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
