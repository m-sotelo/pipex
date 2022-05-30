/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:24:44 by msotelo-          #+#    #+#             */
/*   Updated: 2021/09/28 17:08:17 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len-- > 0)
			*(a + len) = *(b + len);
	else
		while (len-- > 0)
			*(a++) = *(b++);
	return (dst);
}
