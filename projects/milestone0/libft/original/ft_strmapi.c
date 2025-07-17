/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:30:41 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/14 18:06:16 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*t;

	if (!s)
		return (NULL);
	t = ft_strdup(s);
	if (!t)
		return (NULL);
	i = 0;
	while (s[i])
	{
		t[i] = f(i, s[i]);
		i++;
	}
	return (t);
}
