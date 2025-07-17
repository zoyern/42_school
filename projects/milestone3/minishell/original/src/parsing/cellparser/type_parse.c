/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/07/09 02:23:45 by tauer             #+#    #+#             */
/*   Updated: 2024/09/19 17:51:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/all.h>

bool	t_word_parse_cmd(t_mini *mini, t_word *word)
{
	char	*path;
	char	*current_path;
	char	**parse_path;
	ssize_t	index;

	if (!access(t_word_to_str(mini, word), X_OK | F_OK))
		return (word->type = CMD_TYPE, true);
	path = get_envpl_var(mini, "PATH");
	if (!path)
		return (false);
	parse_path = mini->libft->split(mini->solib, path, ':');
	index = -1;
	while (parse_path[++index])
	{
		current_path = mini->libft->strjoin(mini->solib,
				mini->libft->strjoin(mini->solib, parse_path[index], "/"),
				word->refined_word);
		if (!access(current_path, X_OK | F_OK))
			return (word->type = CMD_TYPE, true);
	}
	return (false);
}

bool	t_word_parse_redirect(t_word *word)
{
	if (!word->c || !word->c->next)
		return (false);
	else if (word->c->c == '<' && word->c->next->c == '<'
		&& word->c->next->next)
		return (word->type = CONCATE_IN_FD_TYPE, true);
	else if (word->c->c == '>' && word->c->next->c == '>'
		&& word->c->next->next)
		return (word->type = CONCATE_OUT_FD_TYPE, true);
	else if (word->c->c == '<' && word->c->next->c != '>'
		&& word->c->next->c != '<')
		return (word->type = REPLACE_IN_FD_TYPE, true);
	else if (word->c->c == '>' && word->c->next->c != '>'
		&& word->c->next->c != '<')
		return (word->type = REPLACE_OUT_FD_TYPE, true);
	else
		return (true);
	return (false);
}

bool	t_word_parse_para(t_word *word)
{
	t_char	*current;

	if (!word->c || word->c->c != '-' || !word->c->next || (word->c->next->next
			&& word->c->next->c != word->c->next->next->c))
		return (false);
	else if (word->c->c == '-' && word->c->next && word->c->next->c == '-')
		return (false);
	current = word->c->next;
	while (current)
	{
		if (current->c != word->c->next->c)
			return (false);
		current = current->next;
	}
	return (word->type = PARA_TYPE, true);
}

bool	t_word_parse_built_in(t_mini *mini, t_word *word)
{
	if (!word || !word->refined_word)
		return (false);
	else if (!mini->libft->strncmp(word->refined_word, "exit", 4)
		|| !mini->libft->strncmp(word->refined_word, "cd", 2)
		|| !mini->libft->strncmp(word->refined_word, "./", 2)
		|| !mini->libft->strncmp(word->refined_word, "pwd", 3)
		|| !mini->libft->strncmp(word->refined_word, "export", 6)
		|| !mini->libft->strncmp(word->refined_word, "unset", 5
			|| !mini->libft->strncmp(word->refined_word, "env", 3)))
		return (word->type = BUILT_IN_TYPE, true);
	return (false);
}

bool	t_word_parse_type(t_mini *mini, t_word *word)
{
	if (!word || !word->c)
		return (word->type = ERROR_TYPE, true);
	else if (word->c->c == ';' && !word->c->next)
		return (word->type = SEPARATOR_TYPE, true);
	else if (t_word_parse_built_in(mini, word) || t_word_parse_para(word)
		|| t_word_parse_cmd(mini, word) || t_word_parse_redirect(word))
		return (true);
	return (word->type = ARG_TYPE, false);
}
