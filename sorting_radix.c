/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:15:28 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/15 18:52:28 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_node **stack)
{
	t_node			*first;
	long long		max;
	long long		temp;

	first = *stack;
	max = first->index;
	temp = 0;
	while (first)
	{
		if (first->index > max)
			max = first->index;
		first = first->next;
	}
	while ((max >> temp) != 0)
		temp++;
	return (temp);
}

static void	sort_bits(t_node **stack_a, t_node **stack_b, int bit)
{
	t_node	*temp;
	int		size;
	int		j;

	size = node_counter(*stack_a);
	j = 0;
	while (j < size)
	{
		temp = *stack_a;
		if (((temp->index >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int				max_b;
	int				i;

	put_new_index(stack_a);
	max_b = max_bits(stack_a);
	i = 0;
	while (i < max_b)
	{
		sort_bits(stack_a, stack_b, i);
		i++;
	}
}
