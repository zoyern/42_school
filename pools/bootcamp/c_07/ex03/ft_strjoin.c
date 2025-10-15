/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 06:43:07 by almounib          #+#    #+#             */
/*   Updated: 2023/09/25 15:28:21 by almounib         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*mal_str(int size, char **strs, char *sep, int mal_size)
{
	char	*dup;
	int		i_tab;

	i_tab = 0;
	if (size == 0)
		mal_size = 0;
	while (i_tab < size)
	{
		mal_size += ft_strlen(strs[i_tab]);
		if (i_tab <= (size - 1))
			mal_size += ft_strlen(sep);
		i_tab++;
	}
	dup = (char *)malloc(sizeof(char) * (mal_size + 1));
	if (!(dup))
		return (NULL);
	dup[0] = 0;
	return (dup);
}

char	*inoutput_join(int size, char **strs, char *sep)
{
	char	*dup;
	int		i_tab;

	i_tab = 0;
	dup = mal_str(size, strs, sep, 0);
	while (i_tab < size)
	{
		ft_strcat(dup, strs[i_tab]);
		if (i_tab < (size - 1))
		{
			ft_strcat(dup, sep);
		}
		i_tab++;
	}
	return (dup);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*size_ret;

	if (size == 0)
	{
		size_ret = (char *)malloc(sizeof(char) * 1);
		if (!(size_ret))
			return (NULL);
		size_ret[0] = '\0';
		return (size_ret);
	}
	if (!(sep))
		return (NULL);
	if (!(strs))
		return (NULL);
	return (inoutput_join(size, strs, sep));
}
