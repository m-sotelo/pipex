/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:09:41 by msotelo-          #+#    #+#             */
/*   Updated: 2021/06/16 13:21:20 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	int					i;

	i = 0;
	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	if (n == 0 || (a == b))
	{
		return (dst);
	}
	while (n > 0)
	{
		a[i] = b[i];
		i++;
		n--;
	}
	return (dst);
}
