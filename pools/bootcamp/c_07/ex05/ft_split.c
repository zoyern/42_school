/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 07:23:05 by almounib          #+#    #+#             */
/*   Updated: 2023/09/25 13:13:43 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i + 1])
	{
		if (is_sep(str[i], charset) && !is_sep(str[i + 1], charset))
			count++;
		if (i == 0 && !is_sep(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

char	*malloc_str(char *str, char *charset, int *pos)
{
	char	*dup;
	int		len;

	len = 0;
	while (is_sep(str[*pos], charset))
		(*pos)++;
	while (!is_sep(str[*pos], charset) && str[*pos] != '\0')
	{
		(*pos)++;
		len++;
	}
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	*pos -= len;
	len = 0;
	while (!is_sep(str[*pos], charset) && str[*pos] != '\0')
	{
		dup[len] = str[*pos];
		len++;
		(*pos)++;
	}
	dup[len] = '\0';
	return (dup);
}

char	**output_split(char *str, char *charset)
{
	char	**strs;
	int		count;
	int		i;
	int		pos;

	count = ft_count_word(str, charset);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pos = 0;
		strs[i] = malloc_str(str, charset, &pos);
		str += pos;
		i++;
	}
	strs[i] = 0;
	return (strs);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;

	if (!str)
		return (NULL);
	strs = output_split(str, charset);
	return (strs);
}
