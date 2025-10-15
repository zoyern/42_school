/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:23:14 by almounib          #+#    #+#             */
/*   Updated: 2023/09/19 16:56:22 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_filltab(int *tab, int min, int max)
{
	int	i;

	i = 0;
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	lenght;

	lenght = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	tab = (int *)malloc(sizeof(int) * (lenght + 1));
	if (!tab)
	{
		range = NULL;
		return (-1);
	}
	ft_filltab(tab, min, max);
	*range = tab;
	return (lenght);
}
