/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:53:57 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/07 17:57:17 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	if (s[0] != c && s[0])
		j = 1;
	else
		j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
		i++;
	}
	return (j);
}

static char	**mem_freedom(char **out, int i, int j)
{
	int	k;

	k = j - i;
	while (k >= 0)
	{
		free(out[k]);
		k--;
	}
	free(out);
	out = NULL;
	return (out);
}

static char	**memsplit(const char *s, char c, char **out, int i)
{
	int		k;
	char	**aux;

	out = (char **)ft_calloc((i + 1), sizeof(char *));
	if (!out)
		return (NULL);
	aux = out;
	while (i > 0)
	{
		while (*s == c && *s)
			s++;
		k = 0;
		while (*s != c && *s)
		{
			k++;
			s++;
		}
		*out = (char *)ft_calloc((k + 1), sizeof(char));
		if (!*out)
			return (mem_freedom(out, i, word_count(s, c)));
		out++;
		i--;
	}
	return (aux);
}

static char	**subsplit(const char *s, char c, char **out, int i)
{
	int		j;
	char	**aux;

	j = 0;
	aux = out;
	while (i > 0 && *s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			*(*out + j++) = *s++;
		j = 0;
		out++;
		i--;
	}
	return (aux);
}

char	**ft_split(const char *s, char c)
{
	char	**out;
	int		i;

	i = word_count(s, c);
	out = NULL;
	out = memsplit(s, c, out, i);
	if (out == NULL)
		return (NULL);
	out = subsplit(s, c, out, i);
	return (out);
}

/*int main()
{
	char    *s = "      split       this for   me  !       ";
	int	i  = 0;
	char **s2 = ft_split(s, ' ');
	while(i < 6)
	{
		printf("%s\n"	,s2[i]);
		i++;
	}
	if (!s2)
		printf("PUTA");
}*/
