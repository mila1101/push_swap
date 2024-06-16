/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:52:33 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/16 13:24:22 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_node **first)
{
	int		swapped;
	int		temp;
	t_node	*curr;

	if (*first == NULL || (*first)->next == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		curr = *first;
		while (curr->next != NULL)
		{
			if (curr->x > curr->next->x)
			{
				temp = curr->x;
				curr->x = curr->next->x;
				curr->next->x = temp;
				swapped = 1;
			}
			curr = curr->next;
		}
	}
}

t_node	*clone_stack(t_node **stack_a)
{
	t_node	*curr;
	t_node	*last;
	t_node	*clone;
	t_node	*new_stack;

	curr = *stack_a;
	last = NULL;
	new_stack = NULL;
	while (curr != NULL)
	{
		clone = (t_node *)malloc(sizeof(t_node));
		clone->x = curr->x;
		clone->next = NULL;
		if (last == NULL)
			new_stack = clone;
		else
			last->next = clone;
		last = clone;
		curr = curr->next;
	}
	bubble_sort(&new_stack);
	return (new_stack);
}

void	give_index(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp)
	{
		temp->index = temp->x;
		temp = temp->next;
	}
}

void	new_index(t_node *stack)
{
	t_node	*temp;
	int		i;

	temp = stack;
	i = 0;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

void	put_new_index(t_node **stack_a)
{
	t_node	*clone;
	t_node	*curr;
	t_node	*curr_c;

	clone = clone_stack(stack_a);
	new_index(clone);
	curr_c = clone;
	while (curr_c)
	{
		curr = *stack_a;
		while (curr)
		{
			if (curr_c->x == curr->x)
				curr->index = curr_c->index;
			curr = curr->next;
		}
		curr_c = curr_c->next;
	}
	free_stack(&clone);
}
