/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 21:08:02 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/02 17:46:39 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	just_numbers(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (ft_strlen(av[i]) == 0)
			return (0);
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != ' ' \
			&& av[i][j] != '-' && av[i][j] != '+')
				return (0);
			if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j - 1]))
				return (0);
			if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j + 1] < '0' \
			|| av[i][j + 1] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	no_duplicate(int nb, char **str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 1;
	while (i <= nb)
	{
		j = i + 1;
		while (j <= nb)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_error(int ac, char **av)
{
	if (ac < 2)
		exit(0);
	if (!just_numbers(av) || !no_duplicate(ac - 1, av) || av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	check_error(ac, av);
	stack_a = (t_list *)malloc(sizeof(t_list));
	stack_b = (t_list *)malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		free_all(stack_a, stack_b);
	list_init(stack_a, ac - 1);
	list_init(stack_b, 0);
	while (i < ac)
	{
		fill_struct_a(stack_a, av[i]);
		i++;
	}
	if (stack_a->head == stack_a->tail || is_sorted_a(stack_a))
		free_all(stack_a, stack_b);
	get_index_length(stack_a);
	algo(stack_a, stack_b, stack_a->length);
	free_all(stack_a, stack_b);
	return (0);
}
