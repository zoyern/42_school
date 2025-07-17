/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:34:15 by almounib          #+#    #+#             */
/*   Updated: 2023/12/14 00:56:51 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa_base(unsigned long n, unsigned long base, char *ref_base)
{
	unsigned long	size;
	char			*result;

	if (base < 2 || base > 16)
		return (NULL);
	size = ft_unbrlen_base(n, base);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = 0;
	if (!n)
		result[0] = '0';
	while (n > 0)
	{
		result[size--] = ref_base[n % base];
		n /= base;
	}
	return (result);
}
