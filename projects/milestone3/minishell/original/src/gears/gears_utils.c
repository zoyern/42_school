/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:08:01 by marvin            #+#    #+#             */
/*   Updated: 2024/06/05 18:08:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/all.h>
#include <solibft/sostring.h>

char	*skipc(char **s, char c)
{
	if (!s || !*s || !**s)
		return (NULL);
	while (**s && **s == c && **s != ' ')
		(*s)++;
	if (**s == ' ')
		(*s)++;
	return (*s);
}

char	*changec(char *s, char *c, char *to)
{
	int	i;
	int	j;

	if (!s || !*s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		j = -1;
		while (c[++j])
		{
			if (c[j] == s[i])
				s[i] = to[j % ft_strlen(to)];
		}
	}
	return (s);
}

int	get_c(char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*add_c_end(t_solib *solib, char **str, char c)
{
	char	*new_str;
	int		len;

	len = ft_strlen(*str);
	new_str = somalloc(solib, sizeof(char) * (len + 2));
	ft_strlcpy(new_str, *str, len + 1);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	if (*str)
		free(*str);
	*str = new_str;
	return (new_str);
}

char	*display_prompt(t_mini *mini)
{
	char	*pwd;
	char	*prompt;

	pwd = getcwd(NULL, 0);
	prompt = soprintf_get(mini->solib,
			"%s %C-i#57219e#292929( %s %C-b#696969() \
%C-b#0000ff(%s) )%C#292929() ",
			get_envpl_var(mini, "SHLVL"),
			pwd,
			get_envpl_var(mini, "USER"));
	free(pwd);
	return (prompt);
}
