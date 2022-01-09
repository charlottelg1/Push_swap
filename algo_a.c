/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:56:15 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:14:42 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_under_head(t_list *stack, int median)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->head;
	while (node->data > median)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	find_under_tail(t_list *stack, int median)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->tail;
	while (node->data > median)
	{
		i++;
		node = node->previous;
	}
	return (i);
}

int	part_median_a(t_list *stack_a, t_list *stack_b, int median)
{
	int	under_head;
	int	under_tail;
	int	size_med;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size_med = 0;
	under_head = find_under_head(stack_a, median);
	under_tail = find_under_tail(stack_a, median);
	while (!all_above(stack_a, median) && stack_a->head)
	{
		if (stack_a->head->data <= median)
			part_median_a_short(stack_a, stack_b, &size_med);
		else if (under_tail < under_head)
			part_median_a_shorter(stack_a, &i, 1);
		else
			part_median_a_shorter(stack_a, &i, 2);
		if (stack_b->head)
			part_median_a_even_shorter(stack_b);
	}
	need_swap(stack_a, stack_b);
	part_median_a_short_last(stack_a, i, j);
	return (size_med);
}
