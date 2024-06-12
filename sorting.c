/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:22:22 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/07 13:25:01 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	node_counter(t_node *first)
{
	int		count;
	t_node	*curr;

	count = 0;
	curr = first;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

int	sorted_stack(t_node *stack_a)
{
	t_node	*temp;

	temp = stack_a;
	while (temp->next)
	{
		if (temp->x > temp->next->x)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sort_three(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	if ((temp->x > temp->next->x) && (temp->x > temp->next->next->x))
	{
		if (temp->next->x > temp->next->next->x)
		{
			ra(stack_a);
			sa(stack_a);
		}
		else
			ra(stack_a);
	}
	else if ((temp->x < temp->next->x) && (temp->next->next->x < temp->next->x))
	{
		if (temp->x > temp->next->next->x)
			rra(stack_a);
		else
		{
			sa(stack_a);
			ra(stack_a);
		}
	}
	else if ((temp->x > temp->next->x) && (temp->x < temp->next->next->x))
		sa(stack_a);
}
