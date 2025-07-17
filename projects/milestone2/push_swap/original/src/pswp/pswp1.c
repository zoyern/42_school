/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:16:38 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>
#include <sotypes/soprintf.h>

int	pswp_pa(t_pswp *pswp)
{
	if (!pswp->stack_b)
		return (0);
	push_swap_list_add_obj(&pswp->stack_a,
		push_swap_list_remove(&pswp->stack_b, 0));
	soprintf("pa\n");
	return (1);
}

int	pswp_pb(t_pswp *pswp)
{
	if (!pswp->stack_a)
		return (0);
	push_swap_list_add_obj(&pswp->stack_b,
		push_swap_list_remove(&pswp->stack_a, 0));
	soprintf("pb\n");
	return (1);
}
