/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:05:56 by almounib          #+#    #+#             */
/*   Updated: 2023/09/06 16:36:24 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char centaine, char dizaine, char unite)
{
	write(1, &centaine, 1);
	write(1, &dizaine, 1);
	write(1, &unite, 1);
	if (centaine < '7')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	int	centaine;
	int	dizaine;
	int	unite;

	centaine = 0;
	dizaine = centaine + 1;
	unite = dizaine + 1;
	while (centaine <= 7)
	{
		dizaine = centaine + 1;
		while (dizaine <= 8)
		{
			unite = dizaine + 1;
			while (unite <= 9)
			{
				ft_print(centaine + '0', dizaine + '0', unite + '0');
				unite++;
			}
			dizaine++;
		}
		centaine++;
	}
}
