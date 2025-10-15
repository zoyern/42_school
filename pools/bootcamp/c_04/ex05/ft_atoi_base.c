/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:33:28 by almounib          #+#    #+#             */
/*   Updated: 2023/09/19 19:47:18 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
			return (0);
		j = 0;
		while (j < base_len)
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	return (base_len);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	num;
	int	base_len;

	i = 0;
	sign = 1;
	num = 0;
	base_len = check_base(base);
	if (base_len < 1)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (get_index(str[i], base) >= 0)
	{
		num = (num * base_len) + get_index(str[i], base);
		i++;
	}
	return (num * sign);
}
