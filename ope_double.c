/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:48:50 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 23:04:11 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_double(t_list *stack_a, t_list *stack_b)
{
	int	first;
	int	second;

	first = stack_a->head->data;
	second = stack_a->head->next->data;
	stack_a->head->data = second;
	stack_a->head->index = 0;
	stack_a->head->next->data = first;
	stack_a->head->next->index = 1;
	get_index_length(stack_a);
	first = stack_b->head->data;
	second = stack_b->head->next->data;
	stack_b->head->data = second;
	stack_b->head->index = 0;
	stack_b->head->next->data = first;
	stack_b->head->next->index = 1;
	get_index_length(stack_b);
	write(1, "ss\n", 3);
}
