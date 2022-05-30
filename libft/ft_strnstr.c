/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:34:17 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/16 18:08:41 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>

static char	*aux(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	len_n;
	size_t	len_h;

	len_n = ft_strlen(needle);
	len_h = ft_strlen(haystack);
	j = 0;
	if (len_n > len_h)
		return (NULL);
	if (len > len_h)
		len = len_h;
	while (j < len && haystack[j])
	{	
		if (haystack[j] == needle[0])
		{
			if (!ft_strncmp(&haystack[j], needle, len_n))
			{
				if (j + len_n <= len)
					return ((char *)&haystack[j]);
			}
		}
		j++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	haystack = aux(haystack, needle, len);
	if (haystack == NULL)
		return (NULL);
	else
		return ((char *)haystack);
}
