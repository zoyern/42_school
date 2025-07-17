/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:49:47 by zoyern            #+#    #+#             */
/*   Updated: 2023/12/14 00:56:37 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *s, ...);
unsigned long	ft_printf_operator(const char *s, va_list args, int fd);
unsigned long	ft_putnchar_fd(char c, int fd);
unsigned long	ft_putnstr_fd(const char *s, int fd);
unsigned long	ft_putnptr_fd(void *ptr, int fd);
unsigned long	ft_putnnbr_base_fd(long long nb, int base, int lower, int fd);
unsigned long	ft_uputnnbr_base_fd(
					unsigned int nb, int base, int lower, int fd);
//utils
int				ft_neg_to_pos(int *nb);
int				ft_strncmp(const char *s1, const char *s2, unsigned long n);
char			*ft_get_base(int base, int lower);
char			*ft_itoa_base(long long n, int base, char *ref_base);
char			*ft_uitoa_base(
					unsigned long n, unsigned long base, char *ref_base);
unsigned long	ft_nbrlen(int nb);
unsigned long	ft_nbrlen_base(long long n, int base, unsigned long *sign);
unsigned long	ft_unbrlen_base(unsigned long n, int base);

#endif