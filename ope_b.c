/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:51:01 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 16:39:15 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list *stack)
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
	write(1, "sb\n", 3);
}

void	push_b(t_list *stack_a, t_list *stack_b)
{
	t_node	*first_b;
	t_node	*first_a;

	first_a = stack_a->head;
	first_b = NULL;
	if (stack_a->head->next)
	{
		stack_a->head = stack_a->head->next;
		stack_a->head->previous = NULL;
	}
	else
		list_init(stack_a, 0);
	if (stack_b->head)
		push_b_short(stack_b, first_a, first_b);
	else
	{
		stack_b->head = first_a;
		stack_b->tail = first_a;
		first_a->next = NULL;
		first_a->previous = NULL;
	}
	get_index_length(stack_a);
	get_index_length(stack_b);
	write(1, "pb\n", 3);
}

void	rotate_b(t_list *stack)
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
	write(1, "rb\n", 3);
}

void	reverse_rotate_b(t_list *stack)
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
	write(1, "rrb\n", 4);
}
