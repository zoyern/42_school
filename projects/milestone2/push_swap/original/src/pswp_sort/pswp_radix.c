/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:07:56 by almounib          #+#    #+#             */
/*   Updated: 2024/05/20 17:42:36 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap/all.h>

void	pswp_presort(unsigned long lenght, t_pswp_stack *stack)
{
	t_pswp_stack	*current;
	t_pswp_stack	*tmp;
	unsigned long	count;

	current = stack;
	while (current)
	{
		tmp = stack;
		count = 0;
		while (tmp)
		{
			if (current->id != tmp->id && current->nbr < tmp->nbr)
				count++;
			tmp = tmp->next;
		}
		current->index = (lenght - 1) - count;
		current = current->next;
	}
}

unsigned long	pswp_compare_bit(unsigned long index, unsigned long big_bit)
{
	unsigned long	i;
	unsigned long	bit;

	i = 31;
	while (i--)
	{
		bit = (index >> i & 1);
		if (bit)
			if (i > big_bit)
				return (i);
	}
	return (big_bit);
}

unsigned long	pswp_big_bit(t_pswp_stack *stack)
{
	t_pswp_stack	*current;
	unsigned long	big_bit;

	current = stack;
	big_bit = 0;
	while (current)
	{
		big_bit = pswp_compare_bit(current->index, big_bit);
		current = current->next;
	}
	return (big_bit);
}

int	pswp_radix(t_pswp *pswp)
{
	unsigned long	big_bit;
	unsigned long	i;
	unsigned long	index;
	int				count;

	big_bit = pswp_big_bit(pswp->stack_a);
	i = 0;
	count = 0;
	while (i <= big_bit && is_sorted(pswp->stack_a))
	{
		index = 0;
		while (index < pswp->lenght)
		{
			if (((pswp->stack_a->index >> i) & 1) == 0)
				count += pswp_pb(pswp);
			else
				count += pswp_ra(pswp);
			index++;
		}
		while (pswp->stack_b)
			count += pswp_pa(pswp);
		i++;
	}
	return (count);
}
