/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:12:54 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/06 11:15:30 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_node **stack_a)
{
	t_node	*temp;
	int		min;

	temp = *stack_a;
	min = temp->index;
	while (temp != NULL)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	steps_from_first(t_node **stack_a, int index)
{
	t_node	*temp;
	int		steps;

	steps = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index == index)
			break ;
		steps++;
		temp = temp->next;
	}
	return (steps);
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	steps;

	steps = steps_from_first(stack_a, find_min(stack_a));
	if (steps == 1)
	{
		ra(stack_a);
	}
	else if (steps == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (steps == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	steps;

	steps = steps_from_first(stack_a, find_min(stack_a));
	if (steps == 1)
		ra(stack_a);
	else if (steps == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (steps == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (steps == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
