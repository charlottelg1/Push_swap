/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:53:41 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:31:42 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_swap_push_a(t_list *stack_a, t_list *stack_b)
{
	need_swap(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	call_rotate_a(t_list *stack_a, int i)
{
	while (i > 0)
	{
		rotate_a(stack_a);
		i--;
	}
}

void	call_reverse_a(t_list *stack_a, int i)
{
	while (i > 0)
	{
		reverse_rotate_a(stack_a);
		i--;
	}
}
