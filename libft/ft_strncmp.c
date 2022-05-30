/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:11:53 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/06 23:49:04 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	j;
	int				res;

	j = 0;
	while (j < n && (s1[j] || s2[j]))
	{
		if ((s1[j] == s2[j]) && (s1[j] != '\0') && (s2[j] != '\0'))
		{
			j++;
		}
		else
		{
			res = (unsigned char)s1[j] - (unsigned char)s2[j];
			return (res);
		}
	}
	return (0);
}
