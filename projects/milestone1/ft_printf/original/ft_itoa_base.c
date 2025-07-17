/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:08:09 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:54:18 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long n, int base, char *ref_base)
{
	unsigned long	size;
	char			*result;
	unsigned long	sign;

	if (base < 2 || base > 16)
		return (NULL);
	sign = 0;
	size = ft_nbrlen_base(n, base, &sign);
	result = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (!result)
		return (NULL);
	result[sign + size--] = 0;
	if (sign)
	{
		n = -n;
		result[0] = '-';
	}
	else if (!n)
		result[0] = '0';
	while (n > 0)
	{
		result[sign + size--] = ref_base[n % base];
		n /= base;
	}
	return (result);
}
