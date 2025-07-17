/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyern <zoyern@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:14:45 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/13 21:44:28 by zoyern           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned long start, unsigned long len)
{
	char			*t;
	unsigned long	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (len > i)
		len = i;
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	ft_strlcpy(t, s + start, len + 1);
	return (t);
}
