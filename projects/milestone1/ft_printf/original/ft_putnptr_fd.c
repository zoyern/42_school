/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnptr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:07:15 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:45:16 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putnptr_fd(void *ptr, int fd)
{
	unsigned long		count;
	char				*num;

	if (!ptr)
		return (write(fd, "(nil)", 5));
	count = 0;
	num = ft_uitoa_base((unsigned long)ptr, 16, "0123456789abcdef");
	if (!num)
		return (write(fd, "(nil)", 5));
	count += ft_putnstr_fd("0x", fd);
	count += ft_putnstr_fd(num, fd);
	free(num);
	return (count);
}
