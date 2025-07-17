/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_list_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:32:09 by almounib          #+#    #+#             */
/*   Updated: 2024/05/20 17:37:35 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>

t_pswp_stack	*push_swap_list_revoke(t_pswp_stack *current, t_pswp_stack *tmp)
{
	current->next = current->next->next;
	if (current->next)
		current->next->prev = tmp->prev;
	push_swap_update_id(tmp);
	return (tmp);
}

t_pswp_stack	*push_swap_list_remove(t_pswp_stack **stack, int id)
{
	t_pswp_stack	*current;
	t_pswp_stack	*tmp;
	int				lenght;

	lenght = get_list_lenght(*stack);
	if (id > lenght - 1)
		id = lenght - 1;
	current = *stack;
	if (current && current->id == id)
	{
		*stack = current->next;
		if (*stack)
			(*stack)->prev = current->prev;
		push_swap_update_id(current);
		return (current);
	}
	while (current->next)
	{
		tmp = current->next;
		if (current->next->id == id)
			return (push_swap_list_revoke(current, tmp));
		current = tmp;
	}
	return (NULL);
}
