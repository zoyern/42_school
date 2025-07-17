/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:03:21 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/11 19:25:15 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_putnstr_fd(const char *s, int fd)
{
	unsigned long	count;

	if (!s)
		return (write(fd, "(null)", 6));
	count = 0;
	while (*s)
		count += write (fd, &*(s)++, 1);
	return (count);
}
