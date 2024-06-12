/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:55:49 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/12 15:07:41 by msoklova         ###   ########.fr       */
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

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*curr;

	if (*stack == NULL)
		return ;
	curr = *stack;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*stack = NULL;
}
