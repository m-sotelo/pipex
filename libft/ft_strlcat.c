/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:45:15 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/07 17:34:10 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	int		i;
	int		j;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize > (len_d + len_s + 1))
		j = (int)(len_d + len_s + 1);
	else
		j = (int)dstsize;
	while ((j - (int)len_d) > (i + 1) && src[i] && src[i] != '\0')
	{
		dst[len_d + i] = src[i];
		i++;
	}
	if (dstsize != 0 && len_d < dstsize)
		dst[j - 1] = '\0';
	if (len_d < dstsize)
		return (len_d + len_s);
	return (len_s + dstsize);
}
