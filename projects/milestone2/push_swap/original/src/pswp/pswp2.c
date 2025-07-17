/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:17:04 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>
#include <sotypes/soprintf.h>

int	pswp_ra(t_pswp *pswp)
{
	if (!pswp->stack_a)
		return (0);
	push_swap_list_add_back_obj(&pswp->stack_a,
		push_swap_list_remove(&pswp->stack_a, 0));
	soprintf("ra\n");
	return (1);
}

int	pswp_rb(t_pswp *pswp)
{
	if (!pswp->stack_b)
		return (0);
	push_swap_list_add_back_obj(&pswp->stack_b,
		push_swap_list_remove(&pswp->stack_b, 0));
	soprintf("rb\n");
	return (1);
}

int	pswp_rr(t_pswp *pswp)
{
	int	i;

	i = pswp_ra(pswp);
	i += pswp_rb(pswp);
	return (i);
}
