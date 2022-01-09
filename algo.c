/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:02:47 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 22:44:12 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	all_above(t_list *stack, int median)
{
	t_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (temp->data < median)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	all_under(t_list *stack, int median)
{
	t_node	*temp;

	temp = stack ->head;
	while (temp)
	{
		if (temp->data >= median)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	recurs_back(t_list *stack_a, t_list *stack_b, int len)
{
	int	median;
	int	size_med;

	median = find_median(stack_b, len);
	size_med = part_median_b(stack_a, stack_b, median);
	if (size_med < 6)
	{
		if (size_med == stack_a->length)
			sort_a(stack_a, stack_b);
		else
			sort_top_a(stack_a, stack_b, size_med);
	}
	else
		algo(stack_a, stack_b, size_med);
	if (len - size_med < 6)
		sort_top_b(stack_a, stack_b, len - size_med);
	else
		recurs_back(stack_a, stack_b, len - size_med);
}

void	algo(t_list *stack_a, t_list *stack_b, int len)
{
	int	median;
	int	size_med;

	if (stack_a->length < 6)
	{
		sort_a(stack_a, stack_b);
		return ;
	}
	median = find_median(stack_a, len);
	size_med = part_median_a(stack_a, stack_b, median);
	if (len - size_med < 6)
	{
		if (len - size_med == stack_a->length)
			sort_a(stack_a, stack_b);
		else
			sort_top_a(stack_a, stack_b, len - size_med);
	}
	else
		algo(stack_a, stack_b, len - size_med);
	if (size_med < 6)
		sort_top_b(stack_a, stack_b, size_med);
	else
		recurs_back(stack_a, stack_b, size_med);
}
