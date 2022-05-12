/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:58:19 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/11 19:49:02 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	char	*a;
	int		i;

	i = 0;
	a = (char *)s;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		if (a[i] == (char)c)
		{
			return (&a[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
