/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:34:20 by msotelo-          #+#    #+#             */
/*   Updated: 2021/10/04 16:11:20 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	recursive(int n, int fd)
{
	char	c;

	if (n > 9)
	{
		recursive(n / 10, fd);
		recursive(n % 10, fd);
	}
	else
	{
		c = (char)n + '0';
		ft_putchar_fd(c, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		recursive (-n, fd);
	}
	else
		recursive (n, fd);
}
