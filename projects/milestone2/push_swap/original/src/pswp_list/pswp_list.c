/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:40:46 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>

void	push_swap_update_id(t_pswp_stack *stack)
{
	t_pswp_stack	*tmp;

	tmp = stack->next;
	while (tmp)
	{
		tmp->id--;
		tmp = tmp->next;
	}
}

int	get_list_lenght(t_pswp_stack *stack)
{
	int				lenght;
	t_pswp_stack	*current;

	current = stack;
	lenght = 0;
	while (current)
	{
		lenght++;
		current = current->next;
	}
	return (lenght);
}

t_pswp	*push_swap_list(t_solib *solib, int *nbrs, int len)
{
	t_pswp	*pswp;
	int		i;

	pswp = (t_pswp *)solib->malloc(solib, sizeof(t_pswp));
	pswp->lenght = len;
	pswp->stack_a = NULL;
	pswp->stack_b = NULL;
	i = 0;
	while (i < len)
	{
		push_swap_list_add(solib, &pswp->stack_a, nbrs[i]);
		i++;
	}
	return (pswp);
}
