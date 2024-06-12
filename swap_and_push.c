/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:03:34 by msoklova          #+#    #+#             */
/*   Updated: 2024/05/30 16:30:03 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	int	temp;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = (*a)->x;
		(*a)->x = (*a)->next->x;
		(*a)->next->x = temp;
		write(1, "sa\n", 3);
	}
	else
		return ;
}

void	sb(t_node **b)
{
	int	temp;

	if (*b != NULL && (*b)->next != NULL)
	{
		temp = (*b)->x;
		(*b)->x = (*b)->next->x;
		(*b)->next->x = temp;
		write(1, "sb\n", 3);
	}
	else
		return ;
}

void	ss(t_node **a, t_node **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*b != NULL)
	{
		temp = *b;
		*b = (*b)->next;
		if (*b != NULL)
			(*b)->prev = NULL;
		temp->next = *a;
		if (*a != NULL)
			(*a)->prev = temp;
		*a = temp;
		write(1, "pa\n", 3);
	}
	else
		return ;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		if (*a != NULL)
			(*a)->prev = NULL;
		temp->next = *b;
		if (*b != NULL)
			(*b)->prev = temp;
		*b = temp;
		write(1, "pb\n", 3);
	}
	else
		return ;
}
