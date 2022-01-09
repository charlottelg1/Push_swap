/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:14:37 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/02 17:31:44 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	int		length;
	t_node	*head;
	t_node	*tail;
}	t_list;

/*MAIN*/
int		no_duplicate(int nb, char **str);
int		just_numbers(char **av);

/*INIT*/
void	node_init(t_node *node);
void	fill_struct_a(t_list *stack, char *str);
void	list_init(t_list *stack, int length);
void	get_index_length(t_list *stack);

/*ALGO*/
void	algo(t_list *stack_a, t_list *stack_b, int len);
void	recurs_back(t_list *stack_a, t_list *stack_b, int len);
int		all_above(t_list *stack, int median);
int		all_under(t_list *stack, int median);
int		part_median_a(t_list *stack_a, t_list *stack_b, int median);
int		find_under_tail(t_list *stack, int median);
int		find_under_head(t_list *stack, int median);
int		part_median_b(t_list *stack_a, t_list *stack_b, int median);
int		above_tail(t_list *stack, int median);
int		above_head(t_list *stack, int median);

/*SORT*/
int		*sort_tab(t_list *stack, int *tab, int len);
int		is_sorted_a(t_list *stack);
int		is_sorted_b(t_list *stack);
void	sort_a(t_list *stack_a, t_list *stack_b);
void	sort_three_a(t_list *stack_a, t_list *stack_b);
void	sort_four_a(t_list *stack_a, t_list *stack_b);
void	sort_five_a(t_list *stack_a, t_list *stack_b);
void	sort_b(t_list *stack_a, t_list *stack_b);
void	sort_three_b(t_list *stack);
void	sort_four_b(t_list *stack_a, t_list *stack_b);
void	sort_five_b(t_list *stack_a, t_list *stack_b);

/*SORT TOP*/
void	sort_top_a(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_five_a(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_four_a(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_five_a(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_b(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_three_a(t_list *stack_a, t_list *stack_b, int len);
void	sort_top_four_a(t_list *stack_a, t_list *stack_b, int len);

/*FIND*/
int		find_index_max(t_list *stack);
int		find_index_min(t_list *stack);
int		find_median(t_list*stack, int len);

/*NEED*/
void	need_swap(t_list *stack_a, t_list *stack_b);

/*OPE*/
void	swap_a(t_list *stack);
void	rotate_a(t_list *stack);
void	reverse_rotate_a(t_list *stack);
void	push_a(t_list *stack_a, t_list *stack_b);
void	push_b(t_list *stack_a, t_list *stack_b);
void	rotate_b(t_list *stack);
void	swap_b(t_list *stack);
void	reverse_rotate_b(t_list *stack);
void	swap_double(t_list *stack_a, t_list *stack_b);

/*SHORT*/
void	push_a_short(t_list *stack_a, t_list *stack_b, t_node *first_a, \
		t_node *first_b);
void	push_a_shorter(t_list *stack_a, t_node *first_b );
void	push_b_short(t_list *stack_b, t_node *first_a, t_node *first_b);
void	sort_top_five_a_short(t_list *stack_a, t_list *stack_b);
void	sort_top_five_b_short(t_list *stack_a, t_list *stack_b);
void	part_median_a_short(t_list *stack_a, t_list *stack_b, int *size_med);
void	part_median_a_shorter(t_list *stack_a, int *i, int a);
void	part_median_a_even_shorter(t_list *stack_b);
void	part_median_a_short_last(t_list *stack_a, int i, int j);

/*CALL*/
void	call_rotate_b(t_list *stack_b, int i);
void	call_reverse_b(t_list *stack_b, int i);
void	call_swap_push_a(t_list *stack_a, t_list *stack_b);
void	call_rotate_a(t_list *stack_a, int i);
void	call_reverse_a(t_list *stack_a, int i);
void	call_swap_push_b(t_list *stack_a, t_list *stack_b);

/*UTILS*/
int		checkoverflow(char *str);
int		ft_atoi(char *str);
void	ft_swap(int *a, int *b);
int		ft_strlen(char *str);

/*FREE*/
void	free_stack(t_list *stack);
void	free_all(t_list *stack_a, t_list *stack_b);

#endif
