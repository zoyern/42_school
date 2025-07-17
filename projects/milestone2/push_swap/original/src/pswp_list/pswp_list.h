/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswp_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 01:57:56 by marvin            #+#    #+#             */
/*   Updated: 2024/05/20 17:37:52 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWP_LIST_H
# define PSWP_LIST_H

# include <push_swap/all.h>

void			push_swap_list_add(t_solib *solib,
					t_pswp_stack **stack, int nbr);
void			push_swap_list_add_obj(
					t_pswp_stack **stack, t_pswp_stack *new_stack);
void			push_swap_list_add_back_obj(
					t_pswp_stack **stack, t_pswp_stack *new_stack);
t_pswp_stack	*push_swap_list_remove(t_pswp_stack **stack, int id);
t_pswp			*push_swap_list(t_solib *solib, int *nbrs, int len);
void			push_swap_update_id(t_pswp_stack *stack);
int				get_list_lenght(t_pswp_stack *stack);
t_pswp_stack	*push_swap_list_revoke(
					t_pswp_stack *current, t_pswp_stack *tmp);

#endif
