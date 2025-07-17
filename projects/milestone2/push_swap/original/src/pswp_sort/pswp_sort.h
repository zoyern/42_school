/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_sort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:57:56 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:42:30 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWP_SORT_H
# define PSWP_SORT_H

# include <push_swap/all.h>

int				pswp_two(t_pswp *pswp);
int				pswp_three(t_pswp *pswp);
int				pswp_medium(t_pswp *pswp);
void			pswp_presort(unsigned long lenght, t_pswp_stack *stack);
unsigned long	pswp_compare_bit(unsigned long index, unsigned long big_bit);
unsigned long	pswp_big_bit(t_pswp_stack *stack);
int				pswp_radix(t_pswp *pswp);

#endif
