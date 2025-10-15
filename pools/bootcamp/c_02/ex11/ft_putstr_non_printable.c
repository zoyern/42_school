/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:53:10 by almounib          #+#    #+#             */
/*   Updated: 2023/09/15 12:13:23 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (c >= 32 && c != 127)
		return (1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbrhex(int nb)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
	{
		ft_putnbrhex(nb / 16);
		ft_putnbrhex(nb % 16);
	}
	else
		ft_putchar(hex[nb]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_printable(str[i]))
		{
			ft_putchar('\\');
			if ((unsigned char)str[i] <= 16)
				ft_putchar('0');
			ft_putnbrhex((unsigned char)str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
