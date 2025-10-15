/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 06:02:22 by almounib          #+#    #+#             */
/*   Updated: 2023/09/11 14:32:00 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_iscapital(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_islower(str[i - 1]) && !ft_iscapital(str[i - 1])
			&& !ft_isnumber(str[i - 1]))
		{
			if (ft_islower(str[i]))
			{
				str[i] -= 32;
			}
		}
		else
		{
			if (ft_iscapital(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
