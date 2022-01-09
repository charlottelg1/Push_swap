/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:28:49 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 16:56:44 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max_top(t_list *stack_b, int len)
{
	int		i;
	t_node	*node;
	int		index_max;
	int		data_max;

	i = 0;
	node = stack_b->head;
	index_max = node->index;
	data_max = node->data;
	while (node && i < len)
	{
		if (node->data > data_max)
		{
			data_max = node->data;
			index_max = node->index;
		}
		node = node->next;
		i++;
	}
	return (index_max);
}

void	sort_top_three_b(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_max;

	index_max = find_index_max_top(stack_b, len);
	if (index_max == 0)
	{
		push_a(stack_a, stack_b);
		need_swap(stack_a, stack_b);
	}
	else if (index_max == 1)
	{
		need_swap(stack_a, stack_b);
		push_a(stack_a, stack_b);
		need_swap(stack_a, stack_b);
	}
	else if (index_max == 2)
	{
		need_swap(stack_a, stack_b);
		rotate_b(stack_b);
		need_swap(stack_a, stack_b);
		push_a(stack_a, stack_b);
		reverse_rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_top_four_b(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_max;

	index_max = find_index_max_top(stack_b, len);
	if (index_max == 0)
		push_a(stack_a, stack_b);
	else if (index_max == 1)
		call_swap_push_a(stack_a, stack_b);
	else if (index_max == 2)
	{
		rotate_b(stack_b);
		call_swap_push_a(stack_a, stack_b);
		reverse_rotate_b(stack_b);
	}
	else if (index_max == 3)
	{
		call_rotate_b(stack_b, 2);
		call_swap_push_a(stack_a, stack_b);
		call_reverse_b(stack_b, 2);
	}
	sort_top_three_b(stack_a, stack_b, len - 1);
}

void	sort_top_five_b(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_max;

	index_max = find_index_max_top(stack_b, len);
	if (index_max == 0)
		push_a(stack_a, stack_b);
	else if (index_max == 1)
		call_swap_push_a(stack_a, stack_b);
	else if (index_max == 2)
		sort_top_five_b_short(stack_a, stack_b);
	else if (index_max == 3)
	{
		call_rotate_b(stack_b, 2);
		call_swap_push_a(stack_a, stack_b);
		call_reverse_b(stack_b, 2);
	}
	else if (index_max == 4)
	{
		call_rotate_b(stack_b, 3);
		call_swap_push_a(stack_a, stack_b);
		call_reverse_b(stack_b, 3);
	}
	sort_top_four_b(stack_a, stack_b, len - 1);
}

void	sort_top_b(t_list *stack_a, t_list *stack_b, int len)
{
	if (len == 2)
	{
		need_swap(stack_a, stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	else if (len == 3)
		sort_top_three_b(stack_a, stack_b, len);
	else if (len == 4)
		sort_top_four_b(stack_a, stack_b, len);
	else if (len == 5)
		sort_top_five_b(stack_a, stack_b, len);
}
