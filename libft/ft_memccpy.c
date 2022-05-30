/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:22:27 by msotelo-          #+#    #+#             */
/*   Updated: 2021/09/27 17:42:48 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;

	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	if ((!*b && !*a) || n == 0 || a == b)
	{
		return (NULL);
	}
	while (n > 0)
	{
		*(a) = *(b);
		if (*b == (unsigned char)c)
		{
			return ((void *)++a);
		}
		n--;
		a++;
		b++;
	}
	return (NULL);
}
