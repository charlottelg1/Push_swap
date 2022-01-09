/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:28:28 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:27:34 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_min_top(t_list *stack_b, int len)
{
	int		i;
	t_node	*node;
	int		index_min;
	int		data_min;

	i = 0;
	node = stack_b->head;
	index_min = node->index;
	data_min = node->data;
	while (node && i < len)
	{
		if (node->data < data_min)
		{
			data_min = node->data;
			index_min = node->index;
		}
		node = node->next;
		i++;
	}
	return (index_min);
}

void	sort_top_three_a(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_min;

	index_min = find_index_min_top(stack_a, len);
	if (index_min == 0)
	{
		push_b(stack_a, stack_b);
		need_swap(stack_a, stack_b);
	}
	else if (index_min == 1)
	{
		need_swap(stack_a, stack_b);
		push_b(stack_a, stack_b);
		need_swap(stack_a, stack_b);
	}
	else if (index_min == 2)
	{
		need_swap(stack_a, stack_b);
		rotate_a(stack_a);
		need_swap(stack_a, stack_b);
		push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
		need_swap(stack_a, stack_b);
	}
	push_a(stack_a, stack_b);
}

void	sort_top_four_a(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_min;

	index_min = find_index_min_top(stack_a, len);
	if (index_min == 0)
		push_b(stack_a, stack_b);
	else if (index_min == 1)
		call_swap_push_b(stack_a, stack_b);
	else if (index_min == 2)
	{
		rotate_a(stack_a);
		call_swap_push_b(stack_a, stack_b);
		reverse_rotate_a(stack_a);
	}
	else if (index_min == 3)
	{
		call_rotate_a(stack_a, 2);
		call_swap_push_b(stack_a, stack_b);
		call_reverse_a(stack_a, 2);
	}
	sort_top_three_a(stack_a, stack_b, len - 1);
	push_a(stack_a, stack_b);
}

void	sort_top_five_a(t_list *stack_a, t_list *stack_b, int len)
{
	int	index_min;

	index_min = find_index_min_top(stack_a, len);
	if (index_min == 0)
		push_b(stack_a, stack_b);
	else if (index_min == 1)
		call_swap_push_b(stack_a, stack_b);
	else if (index_min == 2)
		sort_top_five_a_short(stack_a, stack_b);
	else if (index_min == 3)
	{
		call_rotate_a(stack_a, 2);
		call_swap_push_b(stack_a, stack_b);
		call_reverse_a(stack_a, 2);
	}
	else if (index_min == 4)
	{
		call_rotate_a(stack_a, 3);
		call_swap_push_b(stack_a, stack_b);
		call_reverse_a(stack_a, 3);
	}
	sort_top_four_a(stack_a, stack_b, len - 1);
	push_a(stack_a, stack_b);
}

void	sort_top_a(t_list *stack_a, t_list *stack_b, int len)
{
	if (len == 2)
		need_swap(stack_a, stack_b);
	else if (len == 3)
		sort_top_three_a(stack_a, stack_b, len);
	else if (len == 4)
		sort_top_four_a(stack_a, stack_b, len);
	else if (len == 5)
		sort_top_five_a(stack_a, stack_b, len);
}
