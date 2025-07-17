/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:15:49 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>
#include <sotypes/soprintf.h>

int	pswp_sa(t_pswp *pswp)
{
	if (!pswp->stack_a)
		return (0);
	if (!pswp->stack_a->next)
		return (0);
	push_swap_list_add_obj(&pswp->stack_a,
		push_swap_list_remove(&pswp->stack_a, 1));
	soprintf("sa\n");
	return (1);
}

int	pswp_sb(t_pswp *pswp)
{
	if (!pswp->stack_b)
		return (0);
	if (!pswp->stack_b->next)
		return (0);
	push_swap_list_add_obj(&pswp->stack_b,
		push_swap_list_remove(&pswp->stack_b, 1));
	soprintf("sb\n");
	return (1);
}

int	pswp_ss(t_pswp *pswp)
{
	int	i;

	i = pswp_sa(pswp);
	i += pswp_sb(pswp);
	return (i);
}
