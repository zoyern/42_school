/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_list_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:29:48 by almounib          #+#    #+#             */
/*   Updated: 2024/05/20 17:41:45 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>

void	push_swap_list_add(t_solib *solib, t_pswp_stack **stack, int nbr)
{
	t_pswp_stack	*new_stack;
	t_pswp_stack	*current;

	new_stack = (t_pswp_stack *)solib->malloc(solib, sizeof(t_pswp_stack));
	new_stack->nbr = nbr;
	new_stack->index = 0;
	new_stack->next = *stack;
	if (new_stack->next)
		new_stack->next->prev = new_stack;
	*stack = new_stack;
	new_stack->id = 0;
	current = new_stack->next;
	while (current)
	{
		current->id += 1;
		current = current->next;
	}
}

void	push_swap_list_add_back_obj(
			t_pswp_stack **stack, t_pswp_stack *new_stack)
{
	t_pswp_stack	*current;

	if (!new_stack)
		return ;
	current = *stack;
	while (current && current->next)
		current = current->next;
	current->next = new_stack;
	new_stack->prev = current;
	new_stack->next = NULL;
	new_stack->id = current->id + 1;
}

void	push_swap_list_add_obj(t_pswp_stack **stack, t_pswp_stack *new_stack)
{
	t_pswp_stack	*current;

	if (!new_stack)
		return ;
	new_stack->next = *stack;
	new_stack->prev = NULL;
	if (new_stack->next)
		new_stack->next->prev = new_stack;
	*stack = new_stack;
	new_stack->id = 0;
	current = new_stack->next;
	while (current)
	{
		current->id += 1;
		current = current->next;
	}
}
