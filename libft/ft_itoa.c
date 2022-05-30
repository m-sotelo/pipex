/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:58:07 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/05 17:20:10 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_subitoa(int i, int n, int sign)
{
	char	*output;
	int		j;

	output = malloc((i + 2) * sizeof(char));
	j = i;
	if (!output)
		return (NULL);
	if (sign == -1)
		output[0] = '-';
	while (n > 9)
	{
		output[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	output[i] = (n + '0');
	output[j + 1] = '\0';
	return (output);
}

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	j = n;
	sign = 1;
	if (n < 0)
	{
		n = n * (-1);
		j = n;
		sign = -1;
		i++;
	}
	while ((j / 10) > 0)
	{
		j = j / 10;
		i++;
	}
	res = ft_subitoa(i, n, sign);
	return (res);
}
