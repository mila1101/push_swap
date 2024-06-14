/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:15:28 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/14 14:25:24 by msoklova         ###   ########.fr       */
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

void	bubble_sort(t_node **first)
{
	int	swapped;
	int	temp;
	t_node *curr;

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
			last->next =clone;
		last = clone;
		curr = curr->next;
	}
	bubble_sort(&new_stack);
	//printf("this is the clone: ");
	//s_print(new_stack);
	return new_stack;
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
