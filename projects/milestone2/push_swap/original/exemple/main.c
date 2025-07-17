/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:14 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:25:55 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exemple.h"

int	str_isdigit(t_solib *solib, char *str)
{
	if (solib->libft->strlen(str) <= 1 && (str[0] == '+' || str[0] == '-'))
		return (0);
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (*str)
	{
		if (!solib->libft->isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	*strs_to_ints(t_solib *solib, char **strs, int *len)
{
	int		*nbrs;
	int		i;
	long	nbr;

	*len = 0;
	while (strs[*len])
		(*len)++;
	nbrs = solib->malloc(solib, sizeof(int) * (*len + 1));
	i = 0;
	while (strs[i])
	{
		if (!str_isdigit(solib, strs[*len - i - 1]))
			return (solib->free(solib, nbrs), NULL);
		nbr = solib->libft->atoi(strs[*len - i - 1]);
		if (nbr < -2147483648 || nbr > 2147483647)
			return (solib->free(solib, nbrs), NULL);
		nbrs[i] = (int)nbr;
		i++;
	}
	nbrs[i] = 0;
	return (nbrs);
}

int	*split_args_to_int(t_solib *solib, int *len)
{
	int		*nbrs;
	char	**args;

	if (!solib->env->argc)
		return (0);
	else if (solib->env->argc == 1)
		args = solib->libft->split(solib, solib->env->argv[0], ' ');
	else
		args = solib->env->argv;
	nbrs = strs_to_ints(solib, args, len);
	return (nbrs);
}

int	main(int argc, char **argv, char **envp)
{
	t_solib		*solib;
	int			*nbrs;
	int			len;

	solib = sonew_libft(sonew_types(argc, argv, envp));
	if (!solib)
		solib->close(solib, EXIT_FAILURE);
	if (!solib->libft)
		return (solib->close(solib, EXIT_FAILURE));
	if (solib->env->argc == 0)
		return (solib->close(solib, EXIT_SUCCESS));
	if (solib->env->argc == 1
		&& (solib->env->argv[0][0] == '\0' || solib->env->argv[0][0] == ' '))
		return (solib->close(solib, EXIT_SUCCESS));
	nbrs = split_args_to_int(solib, &len);
	if (!nbrs)
		return (solib->print("Error\n"), solib->close(solib, EXIT_SUCCESS));
	if (check_doublon(nbrs))
		return (solib->print("Error\n"), solib->close(solib, EXIT_SUCCESS));
	push_swap(solib, nbrs, len);
	return (solib->close(solib, EXIT_SUCCESS));
}
