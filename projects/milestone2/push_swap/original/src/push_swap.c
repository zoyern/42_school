/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:29 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:40:22 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>
#include <sotypes/soprintf.h>

int	check_doublon(int *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	push_swap_print(char *head, t_pswp *pswp)
{
	t_pswp_stack	*current_a;
	t_pswp_stack	*current_b;

	current_a = pswp->stack_a;
	current_b = pswp->stack_b;
	soprintf("╔══❖═Stack A\t❖ Stack B\t❖\t%s\n", head);
	while ((current_a || current_b))
	{
		if (current_a)
			soprintf("║%C00A3E0(%d~id:%d)|%C7fe132(%d)\t║", \
				current_a->id, current_a->index, current_a->nbr);
		else
			soprintf("║❖            ❖");
		if (current_b)
			soprintf("%C00A3E0(%d~id:%d)|%C7fe132(%d)\n", \
				current_b->id, current_b->index, current_b->nbr);
		else
			soprintf("\n");
		if (current_a)
			current_a = current_a->next;
		if (current_b)
			current_b = current_b->next;
	}
	soprintf("╚══❖════════════❖══════════❖\n");
}

int	is_sorted(t_pswp_stack *stack)
{
	t_pswp_stack	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->nbr > current->next->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_swap(t_solib *solib, int *nbrs, int len)
{
	t_pswp	*pswp;

	if (!nbrs)
		return ;
	pswp = push_swap_list(solib, nbrs, len);
	pswp_presort(pswp->lenght, pswp->stack_a);
	if (!is_sorted(pswp->stack_a))
		return ;
	if (pswp->lenght == 2)
		pswp_two(pswp);
	else if (pswp->lenght <= 5)
		pswp_medium(pswp);
	else
		pswp_radix(pswp);
}
