/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:59:35 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/06 11:14:20 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*temp;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = *a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *a;
		(*a)->prev = temp;
		*a = (*a)->next;
		(*a)->prev->next = NULL;
		(*a)->prev = NULL;
		write(1, "ra\n", 3);
	}
	else
		return ;
}

void	rb(t_node **b)
{
	t_node	*temp;

	if (*b != NULL && (*b)->next != NULL)
	{
		temp = *b;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *b;
		(*b)->prev = temp;
		*b = (*b)->next;
		(*b)->prev->next = NULL;
		(*b)->prev = NULL;
		write(1, "rb\n", 3);
	}
	else
		return ;
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
