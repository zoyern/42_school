/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:52:21 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/14 17:59:58 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s,	const char *needle, unsigned long n)
{
	unsigned long	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)s);
	if (!n)
		return (NULL);
	while (*s && n-- >= needle_len)
	{
		if (!ft_strncmp(s++, needle, needle_len))
			return ((char *)(s -= 1));
	}
	return (NULL);
}
