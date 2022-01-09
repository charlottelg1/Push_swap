/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:56:39 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 22:57:29 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	above_head(t_list *stack, int median)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->head;
	while (node->data < median)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	above_tail(t_list *stack, int median)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->tail;
	while (node->data < median)
	{
		i++;
		node = node->previous;
	}
	return (i);
}

void	under_median_b(t_list *stack_b, int median, int *i)
{
	if (above_tail(stack_b, median) < above_head(stack_b, median))
	{
		reverse_rotate_b(stack_b);
		*i += 1;
	}
	else
	{
		rotate_b(stack_b);
		*i += 1;
	}
}

int	part_median_b(t_list *stack_a, t_list *stack_b, int median)
{
	int	size_med;
	int	i;

	i = 0;
	size_med = 0;
	while (!all_under(stack_b, median) && stack_b->head)
	{
		if (stack_b->head->data >= median)
		{
			push_a(stack_a, stack_b);
			size_med++;
		}
		else
			under_median_b(stack_b, median, &i);
	}
	while (i-- > 0)
		reverse_rotate_b(stack_b);
	return (size_med);
}
