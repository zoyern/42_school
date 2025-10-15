/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:00:10 by almounib          #+#    #+#             */
/*   Updated: 2023/09/19 18:32:41 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 0;
		while (j < base_len)
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			base_len;

	n = nbr;
	base_len = check_base(base);
	if (base_len < 1)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
	else
		ft_putchar(base[n]);
}
