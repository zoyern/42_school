/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:42:59 by zoyern            #+#    #+#             */
/*   Updated: 2023/11/14 18:05:33 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	count_words(char const *s, char c)
{
	unsigned long	i;
	unsigned long	count;

	i = 0;
	count = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c)
			|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char	*malloc_str(char const *s, char c, unsigned long *pos)
{
	char				*dup;
	unsigned long		len;

	len = 0;
	while (s[*pos] == c)
		(*pos)++;
	while ((s[*pos] != c) && s[*pos] != '\0')
	{
		(*pos)++;
		len++;
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	*pos -= len;
	len = 0;
	while ((s[*pos] != c) && s[*pos] != '\0')
	{
		dup[len] = s[*pos];
		(*pos)++;
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	unsigned long		i;
	char				**strs;
	unsigned long		count;
	unsigned long		pos;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pos = 0;
		strs[i] = malloc_str(s, c, &pos);
		s += pos;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
