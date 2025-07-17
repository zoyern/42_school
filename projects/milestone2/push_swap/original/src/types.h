/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:27:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/16 15:11:46 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>
# include <stdlib.h>
# include <solibft.h>

typedef struct s_pswp		t_pswp;
typedef struct s_pswp_stack	t_pswp_stack;

typedef struct s_pswp_stack
{
	int				id;
	int				nbr;
	unsigned long	index;
	t_pswp_stack	*next;
	t_pswp_stack	*prev;
}	t_pswp_stack;

typedef struct s_pswp
{
	unsigned long	lenght;
	t_pswp_stack	*stack_a;
	t_pswp_stack	*stack_b;
}	t_pswp;

#endif