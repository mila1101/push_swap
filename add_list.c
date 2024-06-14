/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:44:00 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/14 14:03:23 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_node **last, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		exit (1);
		return ;
	}
	new_node->x = value;
	new_node->next = NULL;
	if (*last == NULL)
	{
		new_node->prev = NULL;
		*last = new_node;
	}
	else
	{
		new_node->prev = *last;
		(*last)->next = new_node;
		*last = new_node;
	}
}
