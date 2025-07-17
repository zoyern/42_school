/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:42:16 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>

int	pswp_two(t_pswp *pswp)
{
	if (pswp->lenght <= 1)
		return (0);
	if (pswp->stack_a->nbr > pswp->stack_a->next->nbr)
		return (pswp_sa(pswp));
	return (0);
}

int	pswp_three(t_pswp *pswp)
{
	int				count;

	count = 0;
	while (is_sorted(pswp->stack_a))
	{
		if (pswp->stack_a->index > pswp->stack_a->next->index)
			count += pswp_sa(pswp);
		else
			count += pswp_rra(pswp);
	}
	return (count);
}

int	pswp_medium(t_pswp *pswp)
{
	unsigned long	i;
	unsigned long	count;
	unsigned long	iter;

	i = 0;
	count = 0;
	iter = 2;
	if (pswp->lenght == 3)
		return (pswp_three(pswp));
	else if (pswp->lenght == 4)
		iter = 1;
	while (i < iter)
	{
		if (pswp->stack_a->index == i)
			i += pswp_pb(pswp);
		else
			count += pswp_rra(pswp);
	}
	count += i;
	count += pswp_three(pswp);
	if (pswp->lenght == 5 && pswp->stack_b->index < pswp->stack_b->next->index)
		count += pswp_sb(pswp);
	count += pswp_pa(pswp);
	count += pswp_pa(pswp);
	return (count);
}
