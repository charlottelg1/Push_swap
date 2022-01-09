/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:05:59 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 22:37:31 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_list *stack_a, t_list *stack_b)
{
	int	index_max;

	(void)stack_b;
	index_max = find_index_max(stack_a);
	if (index_max == 0)
		rotate_a(stack_a);
	else if (index_max == 1)
		reverse_rotate_a(stack_a);
	if (!is_sorted_a(stack_a))
		need_swap(stack_a, stack_b);
}

void	sort_four_a(t_list *stack_a, t_list *stack_b)
{
	int	index_min;

	index_min = find_index_min(stack_a);
	if (index_min == 1)
		rotate_a(stack_a);
	else if (index_min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (index_min == 3)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_three_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_five_a(t_list *stack_a, t_list *stack_b)
{
	int	index_min;

	index_min = find_index_min(stack_a);
	if (index_min == 1)
		rotate_a(stack_a);
	else if (index_min == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (index_min == 3)
	{
		reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (index_min == 4)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_four_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	sort_a(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->length == 2)
		need_swap(stack_a, stack_b);
	else if (stack_a->length == 3)
		sort_three_a(stack_a, stack_b);
	else if (stack_a->length == 4)
		sort_four_a(stack_a, stack_b);
	else if (stack_a->length == 5)
		sort_five_a(stack_a, stack_b);
}
