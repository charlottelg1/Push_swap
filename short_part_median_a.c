/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_part_median_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:14:17 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/12 17:14:46 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_median_a_short(t_list *stack_a, t_list *stack_b, int *size_med)
{
	push_b(stack_a, stack_b);
	*size_med += 1;
}

void	part_median_a_shorter(t_list *stack_a, int *i, int a)
{
	if (a == 1)
	{
		*i -= 1;
		reverse_rotate_a(stack_a);
	}
	else if (a == 2)
	{
		rotate_a(stack_a);
		*i += 1;
	}
}

void	part_median_a_even_shorter(t_list *stack_b)
{
	if (stack_b->head->data < stack_b->tail->data)
		rotate_b(stack_b);
}

void	part_median_a_short_last(t_list *stack_a, int i, int j)
{
	while (j < i)
	{
		reverse_rotate_a(stack_a);
		j++;
	}
}
