/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:07:15 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:59:30 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putnnbr_base_fd(long long nb, int base, int lower, int fd)
{
	unsigned long	count;
	char			*num;
	char			*ref_base;

	count = 0;
	ref_base = ft_get_base(base, lower);
	if (base == 16 && nb < 0)
		nb = -nb;
	num = ft_itoa_base(nb, base, ref_base);
	if (!num)
		return (0);
	count += ft_putnstr_fd(num, fd);
	free(num);
	free(ref_base);
	return (count);
}
