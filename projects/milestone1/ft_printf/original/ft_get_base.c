/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:48:25 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:33:30 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_base(int base, int lower)
{
	char	*all_digits;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (base + 1));
	if (!res)
		return (NULL);
	if (lower)
		all_digits = "0123456789abcdef";
	else
		all_digits = "0123456789ABCDEF";
	i = -1;
	while (++i < base)
		res[i] = all_digits[i];
	res[base] = '\0';
	return (res);
}
