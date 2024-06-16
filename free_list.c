/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:55:49 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/16 14:43:57 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **first, t_node **last)
{
	t_node	*temp;

	if (*first == NULL)
		return ;
	temp = *first;
	while (temp->next != NULL)
	{
		temp = temp->next;
		free(temp->prev);
	}
	free(temp);
	*first = NULL;
	*last = NULL;
}

void	free_final_stack(t_node **stack)
{
	t_node	*temp;

	while ((*stack)->prev)
		*stack = (*stack)->prev;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	free_stack(t_node **stack)
{
	t_node	*curr;
	t_node	*next_node;

	if (stack == NULL || *stack == NULL)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	*stack = NULL;
}
