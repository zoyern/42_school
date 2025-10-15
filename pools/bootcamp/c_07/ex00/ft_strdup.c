/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 05:31:41 by almounib          #+#    #+#             */
/*   Updated: 2023/09/19 16:53:30 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*str;

	i = 0;
	src_len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (NULL);
	while (i < src_len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
