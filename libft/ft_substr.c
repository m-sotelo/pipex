/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:47:21 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/13 16:06:07 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;
	int				j;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	if (len > ft_strlen(s) - start - 1)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	s1 = malloc ((len + 1) * sizeof (char));
	if (!s1)
		return (NULL);
	while (len > 0 && s[i])
	{
		s1[j] = s[i];
		i++;
		j++;
		len--;
	}
	s1[j] = '\0';
	return (s1);
}
