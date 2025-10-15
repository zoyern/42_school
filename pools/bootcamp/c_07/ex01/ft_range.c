/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:05:16 by almounib          #+#    #+#             */
/*   Updated: 2023/09/19 16:55:23 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	lenght;
	int	*tab;

	i = 0;
	lenght = max - min;
	if (min >= max)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * (lenght + 1));
	if (!tab)
		return (NULL);
	while (i < lenght)
	{
		tab[i] = min;
		min ++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
