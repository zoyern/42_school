/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:17:33 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>
#include <sotypes/soprintf.h>

int	pswp_rra(t_pswp *pswp)
{
	if (!pswp->stack_a)
		return (0);
	push_swap_list_add_obj(&pswp->stack_a,
		push_swap_list_remove(&pswp->stack_a, pswp->lenght));
	soprintf("rra\n");
	return (1);
}

int	pswp_rrb(t_pswp *pswp)
{
	if (!pswp->stack_b)
		return (0);
	push_swap_list_add_obj(&pswp->stack_b,
		push_swap_list_remove(&pswp->stack_b, pswp->lenght));
	soprintf("rrb\n");
	return (1);
}

int	pswp_rrr(t_pswp *pswp)
{
	int	i;

	i = pswp_rra(pswp);
	i += pswp_rrb(pswp);
	return (i);
}
