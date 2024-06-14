/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:49:43 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/14 14:01:29 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*temp;
	t_node	*last;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = *a;
		while (temp->next != NULL)
		{
			last = temp;
			temp = temp->next;
		}
		last->next = NULL;
		temp->next = *a;
		(*a)->prev = temp;
		temp->prev = NULL;
		*a = temp;
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void	rrb(t_node **b)
{
	t_node	*temp;
	t_node	*last;

	if (*b != NULL && (*b) != NULL)
	{
		temp = *b;
		while (temp->next != NULL)
		{
			last = temp;
			temp = temp->next;
		}
		last->next = NULL;
		temp->next = *b;
		(*b)->prev = temp;
		temp->prev = NULL;
		*b = temp;
		write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
