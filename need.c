/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:49:39 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:36:53 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	need_swap(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->head && stack_b->head)
	{
		if (stack_a->head->next && stack_b->head->next)
		{
			if (stack_a->head->data > stack_a->head->next->data && \
			stack_b->head->data < stack_b->head->next->data)
				swap_double(stack_a, stack_b);
			else if (stack_a->head->data > stack_a->head->next->data)
				swap_a(stack_a);
			else if (stack_b->head->data < stack_b->head->next->data)
				swap_b(stack_b);
		}
	}
	else if (stack_a->head && stack_a->head->next)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			swap_a(stack_a);
	}
	else if (stack_b->head && stack_b->head->next)
	{
		if (stack_b->head->data < stack_b->head->next->data)
			swap_b(stack_b);
	}
}
