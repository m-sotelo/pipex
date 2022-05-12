/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:50:34 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/01 19:11:57 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, (int)*(s1 + start)) && *(s1 + start))
		start++;
	if (!*(s1 + start))
		return (ft_strdup(""));
	while (ft_strchr(set, (int)*(s1 + len - 1 - end)) && *(s1 + len - 1 - end))
		end++;
	return (ft_substr(s1, start, len - start - end));
}
