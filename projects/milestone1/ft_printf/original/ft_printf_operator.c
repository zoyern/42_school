/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 00:38:51 by almounib          #+#    #+#             */
/*   Updated: 2023/12/14 00:57:11 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long	ft_printf_operator(const char *s, va_list args, int fd)
{
	if (!ft_strncmp("%", s, 1))
		return (ft_putnchar_fd('%', fd));
	else if (!ft_strncmp("c", s, 1))
		return (ft_putnchar_fd(va_arg(args, int), fd));
	else if (!ft_strncmp("s", s, 1))
		return (ft_putnstr_fd(va_arg(args, char *), fd));
	else if (!ft_strncmp("p", s, 1))
		return (ft_putnptr_fd(va_arg(args, void *), fd));
	else if (!ft_strncmp("d", s, 1))
		return (ft_putnnbr_base_fd(va_arg(args, int), 10, 0, fd));
	else if (!ft_strncmp("i", s, 1))
		return (ft_putnnbr_base_fd(va_arg(args, int), 10, 0, fd));
	else if (!ft_strncmp("u", s, 1))
		return (ft_putnnbr_base_fd(va_arg(args, unsigned int), 10, 0, fd));
	else if (!ft_strncmp("x", s, 1))
		return (ft_uputnnbr_base_fd(va_arg(args, int), 16, 1, fd));
	else if (!ft_strncmp("X", s, 1))
		return (ft_uputnnbr_base_fd(va_arg(args, int), 16, 0, fd));
	else
		return (ft_putnchar_fd(*s, fd));
	return (0);
}
