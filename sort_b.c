/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:32:17 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 23:04:56 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b(t_list *stack_b)
{
	int	index_min;

	index_min = find_index_min(stack_b);
	if (index_min == 0)
		rotate_b(stack_b);
	else if (index_min == 2)
		reverse_rotate_b(stack_b);
	if (!is_sorted_b(stack_b))
		swap_b(stack_b);
}

void	sort_four_b(t_list *stack_a, t_list *stack_b)
{
	int	index_max;

	index_max = find_index_max(stack_b);
	if (index_max == 1)
		rotate_b(stack_b);
	else if (index_max == 2)
	{
		rotate_b(stack_b);
		rotate_b(stack_b);
	}
	else if (index_max == 3)
		reverse_rotate_b(stack_b);
	push_a(stack_a, stack_b);
	sort_three_b(stack_b);
	push_b(stack_a, stack_b);
}

void	sort_five_b(t_list *stack_a, t_list *stack_b)
{
	int	index_max;

	index_max = find_index_max(stack_b);
	if (index_max == 1)
		rotate_b(stack_b);
	else if (index_max == 2)
	{
		rotate_b(stack_b);
		rotate_b(stack_b);
	}
	else if (index_max == 3)
	{
		reverse_rotate_b(stack_b);
		reverse_rotate_b(stack_b);
	}
	else if (index_max == 4)
		reverse_rotate_b(stack_b);
	push_a(stack_a, stack_b);
	sort_four_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	sort_b(t_list *stack_a, t_list *stack_b)
{
	get_index_length(stack_b);
	if (stack_b->length == 2)
		swap_b(stack_b);
	else if (stack_b->length == 3)
		sort_three_b(stack_b);
	else if (stack_b->length == 4)
		sort_four_b(stack_a, stack_b);
	else if (stack_b->length == 5)
		sort_five_b(stack_a, stack_b);
}
