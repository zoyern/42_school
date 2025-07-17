/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:11:38 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/06 01:04:13 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_nbrlen(int nb)
{
	unsigned long	count;

	count = 0;
	count += ft_neg_to_pos(&nb);
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}
