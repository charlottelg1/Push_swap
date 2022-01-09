/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:39:56 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 23:04:30 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_list *stack, int length)
{
	stack->length = length;
	stack->head = NULL;
	stack->tail = NULL;
}

void	node_init(t_node *node)
{
	node->data = 0;
	node->index = 0;
	node->previous = NULL;
	node->next = NULL;
}

void	fill_struct_a(t_list *stack_a, char *str)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!str || !stack_a || !new_node)
		return ;
	node_init(new_node);
	if (!stack_a->head)
	{
		stack_a->head = new_node;
		stack_a->tail = new_node;
	}
	else
	{
		stack_a->tail->next = new_node;
		new_node->previous = stack_a->tail;
		stack_a->tail = new_node;
		new_node->index = (new_node->previous->index) + 1;
	}
	new_node->data = ft_atoi(str);
}

void	get_index_length(t_list *stack)
{
	int		index;
	int		length;
	t_node	*node;

	index = 0;
	length = 0;
	node = stack->head;
	while (node)
	{
		node->index = index;
		node = node->next;
		index++;
	}
	node = stack->head;
	while (node)
	{
		length++;
		node = node->next;
	}
	stack->length = length;
}
