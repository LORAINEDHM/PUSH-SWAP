/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:55:03 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:56:29 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((len + start) > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		len = 0;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start] != '\0')
		{
			dst[i] = s[start];
			i++;
			start++;
		}
	}
	dst[i] = '\0';
	return (dst);
}
