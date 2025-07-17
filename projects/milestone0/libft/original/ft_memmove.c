/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:38:03 by almounib          #+#    #+#             */
/*   Updated: 2023/11/14 18:47:57 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dest == src)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (src < dest)
	{
		while (n--)
			tmp_dest[n] = tmp_src[n];
	}
	else
	{
		while (n--)
			*tmp_dest++ = *tmp_src++;
	}
	return (dest);
}
