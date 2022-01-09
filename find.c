/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:49:50 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 22:23:04 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max(t_list *stack)
{
	int		index_max;
	int		max_data;
	t_node	*temp;

	temp = stack->head;
	index_max = temp->index;
	max_data = temp->data;
	while (temp)
	{
		if (temp->data > max_data)
		{
			index_max = temp->index;
			max_data = temp->data;
		}
		temp = temp->next;
	}
	return (index_max);
}

int	find_index_min(t_list *stack)
{
	int		index_min;
	int		min_data;
	t_node	*temp;

	temp = stack->head;
	index_min = temp->index;
	min_data = temp->data;
	while (temp)
	{
		if (temp->data < min_data)
		{
			min_data = temp->data;
			index_min = temp->index;
		}
		temp = temp->next;
	}
	return (index_min);
}

int	find_median(t_list *stack, int len)
{
	int		median;
	t_list	*temp;
	int		*tab;
	int		middle;

	middle = len / 2;
	tab = (int *)malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	temp = stack;
	tab = sort_tab(temp, tab, len);
	median = tab[middle];
	free(tab);
	tab = NULL;
	return (median);
}
