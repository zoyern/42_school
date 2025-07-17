/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnnbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:41:50 by almounib          #+#    #+#             */
/*   Updated: 2023/12/14 00:57:43 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_uputnnbr_base_fd(
					unsigned int nb, int base, int lower, int fd)
{
	unsigned long	count;
	char			*num;
	char			*ref_base;

	count = 0;
	ref_base = ft_get_base(base, lower);
	num = ft_uitoa_base(nb, base, ref_base);
	if (!num)
		return (0);
	count += ft_putnstr_fd(num, fd);
	free(num);
	free(ref_base);
	return (count);
}
