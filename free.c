/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:41:14 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/02 17:46:31 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	t_node	*temp;
	t_node	*del;

	temp = stack->head;
	while (temp)
	{
		del = temp;
		temp = temp->next;
		free(del);
		del = NULL;
	}
	free(stack);
	stack = NULL;
}

void	free_all(t_list *stack_a, t_list *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit (0);
}
