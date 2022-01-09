/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:23:33 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:24:13 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_short(t_list *stack_b, t_node *first_a, t_node *first_b)
{
	first_b = stack_b->head;
	first_b->previous = first_a;
	first_a->previous = NULL;
	stack_b->head = first_a;
	stack_b->head->next = first_b;
}

void	sort_top_five_b_short(t_list *stack_a, t_list *stack_b)
{
	rotate_b(stack_b);
	call_swap_push_a(stack_a, stack_b);
	reverse_rotate_b(stack_b);
}
