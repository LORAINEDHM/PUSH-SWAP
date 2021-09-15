/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:02:01 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 11:12:07 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_of_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

static size_t	get_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		s++;
		i++;
	}
	return (i);
}

static char	**ft_clear(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word_len;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = ft_calloc(sizeof(*ptr), (num_of_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			word_len = get_word_len(--s, c);
			ptr[j] = ft_substr(s, 0, word_len);
			if (!ptr[j++])
				return (ft_clear(ptr));
			s += word_len;
		}
	}
	return (ptr);
}
