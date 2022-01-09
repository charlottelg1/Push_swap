/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:24:39 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:31:16 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_rotate_b(t_list *stack_b, int i)
{
	while (i > 0)
	{
		rotate_b(stack_b);
		i--;
	}
}

void	call_reverse_b(t_list *stack_b, int i)
{
	while (i > 0)
	{
		reverse_rotate_b(stack_b);
		i--;
	}
}

void	call_swap_push_b(t_list *stack_a, t_list *stack_b)
{
	need_swap(stack_a, stack_b);
	push_b(stack_a, stack_b);
}
