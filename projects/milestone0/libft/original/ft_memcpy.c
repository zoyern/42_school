/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:27:37 by almounib          #+#    #+#             */
/*   Updated: 2023/11/14 18:47:42 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned char	*t;

	if (dest == src)
		return (NULL);
	t = dest;
	while (n--)
		*t++ = *(unsigned char *)src++;
	return (dest);
}
