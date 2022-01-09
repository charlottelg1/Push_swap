/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:38:34 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 16:38:47 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *stack)
{
	int	first;
	int	second;

	first = stack->head->data;
	second = stack->head->next->data;
	stack->head->data = second;
	stack->head->index = 0;
	stack->head->next->data = first;
	stack->head->next->index = 1;
	get_index_length(stack);
	write(1, "sa\n", 3);
}

void	rotate_a(t_list *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	first = NULL;
	second = NULL;
	last = NULL;
	first = stack->head;
	second = stack->head->next;
	last = stack->tail;
	stack->head = second;
	stack->head->previous = NULL;
	stack->tail = first;
	stack->tail->next = NULL;
	stack->tail->previous = last;
	last->next = stack->tail;
	get_index_length(stack);
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_list *stack)
{
	t_node	*first;
	t_node	*ante;
	t_node	*last;

	first = NULL;
	ante = NULL;
	last = NULL;
	first = stack->head;
	ante = stack->tail->previous;
	last = stack->tail;
	stack->head = last;
	stack->head->next = first;
	stack->head->previous = NULL;
	first->previous = stack->head;
	stack->tail = ante;
	stack->tail->next = NULL;
	get_index_length(stack);
	write(1, "rra\n", 4);
}

void	push_a(t_list *stack_a, t_list *stack_b)
{
	t_node	*first_a;
	t_node	*first_b;

	first_a = NULL;
	first_b = stack_b->head;
	if (stack_b->head->next)
	{
		stack_b->head = stack_b->head->next;
		stack_b->head->previous = NULL;
	}
	else
		list_init(stack_b, 0);
	if (stack_a->head)
		push_a_short(stack_a, stack_b, first_a, first_b);
	else
		push_a_shorter(stack_a, first_b);
	if (stack_a->head)
		get_index_length(stack_a);
	if (stack_b->head)
		get_index_length(stack_b);
	write(1, "pa\n", 3);
}
