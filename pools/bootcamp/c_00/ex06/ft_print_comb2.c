/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:37:04 by almounib          #+#    #+#             */
/*   Updated: 2023/09/06 16:55:00 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	write_digit(int digit1, int digit2)
{
	if (digit1 <= 9)
	{
		ft_putchar('0');
	}
	ft_putnbr(digit1);
	ft_putchar(' ');
	if (digit2 <= 9)
	{
		ft_putchar('0');
	}
	ft_putnbr(digit2);
	if (digit1 < 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	digit1;
	int	digit2;

	digit1 = 0;
	digit2 = digit1 + 1;
	while (digit1 <= 98)
	{
		while (digit2 <= 99)
		{
			write_digit(digit1, digit2);
			digit2++;
		}
		digit1++;
		digit2 = digit1 + 1;
	}
}
