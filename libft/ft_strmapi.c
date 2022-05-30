/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 10:02:20 by msotelo-          #+#    #+#             */
/*   Updated: 2021/09/22 11:25:39 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	out = (char *) malloc ((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
