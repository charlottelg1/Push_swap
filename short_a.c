/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:38:28 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:31:24 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_short(t_list *stack_a, t_list *stack_b, t_node *first_a, \
		t_node *first_b)
{
	first_a = stack_a->head;
	first_a->previous = first_b;
	if (stack_b->head)
		stack_b->head->previous = NULL;
	stack_a->head = first_b;
	stack_a->head->next = first_a;
}

void	push_a_shorter(t_list *stack_a, t_node *first_b )
{
	stack_a->head = first_b;
	stack_a->tail = first_b;
	first_b->next = NULL;
	first_b->previous = NULL;
}

void	sort_top_five_a_short(t_list *stack_a, t_list *stack_b)
{
	rotate_a(stack_a);
	call_swap_push_b(stack_a, stack_b);
	reverse_rotate_a(stack_a);
}
