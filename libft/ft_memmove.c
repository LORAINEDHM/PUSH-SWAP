/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:53:16 by lduhamel          #+#    #+#             */
/*   Updated: 2021/09/14 16:29:55 by lduhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	if (!(!dst && !src))
	{
		ptr1 = dst;
		ptr2 = src;
		if (ptr2 < ptr1 && ptr1 < ptr2 + n)
			while (n-- > 0)
				*(ptr1 + n) = *(ptr2 + n);
		else
			ft_memcpy(dst, src, n);
	}
	return (dst);
}
