/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:26:56 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/09 16:26:25 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_nbrlen(int n)
{
	unsigned long	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned long	count;
	int				sign;
	long int		nb;

	nb = n;
	count = ft_nbrlen(nb);
	sign = 0;
	s = (char *)malloc(sizeof(char) * count + 1);
	if (!s)
		return (NULL);
	s[count] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[sign++] = '-';
	}
	while (count-- > (unsigned long)sign)
	{
		s[count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
