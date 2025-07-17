/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:50:34 by zoyern            #+#    #+#             */
/*   Updated: 2024/02/07 14:47:08 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list			args;
	unsigned long	count;
	unsigned long	i;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && (s[i + 1] == '%' || s[i + 1] != '\0'))
			count += ft_printf_operator(s + ++i, args, 1);
		else
			count += ft_putnchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
