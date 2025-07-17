/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:27:13 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:45:14 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_nbrlen_base(long long n, int base, unsigned long *sign)
{
	unsigned long	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		*sign = 1;
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}
