/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:21:05 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/12 15:04:40 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>

typedef struct s_node{
	long long		x;
	long long		index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void		s_print(t_node *stack);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);
void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);
int			ft_atoi(const char *str);
void		add_list(t_node **last, int value);
void		free_list(t_node **first, t_node **last);
void		free_stack(t_node **stack);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
int			input_check(char *argv[]);
int			check_sign(int c);
int			check_space(int c);
int			ft_isdigit(int c);
void		print_error(void);
int			double_space_check(char *argv[]);
int			check_double_nums(t_node *a);
t_node		*quoted_stack(char *argv[]);
t_node		*stack_a(int argc, char *argv[]);
int			node_counter(t_node *first);
int			sorted_stack(t_node *stack_a);
void		give_index(t_node *stack);
void		radix_sort(t_node **stack_a, t_node **stack_b);
int			find_min(t_node **stack_a);
int			steps_from_first(t_node **stack_a, int index);
void		sort_three(t_node **stack_a);
void		sort_four(t_node **stack_a, t_node **stack_b);
void		sort_five(t_node **stack_a, t_node **stack_b);

#endif
