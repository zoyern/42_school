/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:18:16 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/04 18:24:32 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n--)
		if (*t++ == (unsigned char)c)
			return (t -= 1);
	return (NULL);
}
