/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:34:19 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/13 21:08:05 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned long	len;

	len = ft_strlen(s) - 1;
	if (!c)
		return ((char *)s + len + 1);
	s += len;
	while (len-- + 1)
		if (*s-- == (char)c)
			return ((char *)(s += 1));
	return (NULL);
}
