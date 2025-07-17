/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:42:58 by almounib          #+#    #+#             */
/*   Updated: 2023/11/21 16:41:00 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long sz)
{
	unsigned long	dst_len;
	unsigned long	src_len;
	unsigned long	i;

	if (!sz && (!src || !dst))
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (sz <= dst_len || sz < 1)
		return (src_len + sz);
	dst += dst_len;
	while (*src && i++ < sz - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
