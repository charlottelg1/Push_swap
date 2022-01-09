/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:37:12 by cle-gran          #+#    #+#             */
/*   Updated: 2021/12/04 22:38:48 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab(t_list *stack, int *tab, int len)
{
	int		i;
	int		j;
	t_node	*node;

	node = stack->head;
	i = 0;
	while (node && i < len)
	{
		tab[i++] = node->data;
		node = node->next;
	}
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	i = 0;
	return (tab);
}

int	is_sorted_a(t_list *stack)
{
	t_node	*temp;

	if (!stack)
	{
		return (1);
	}
	temp = stack->head;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_sorted_b(t_list *stack)
{
	t_node	*temp;

	if (!stack)
	{
		return (1);
	}
	temp = stack->head;
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
