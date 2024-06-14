/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:26:14 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/14 17:28:06 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

t_node	*quoted_stack(char *argv[])
{
	char	**temp;
	t_node	*first;
	t_node	*last;
	int		i;

	first = NULL;
	last = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i] != NULL)
	{
		add_list(&last, ft_atoi(temp[i]));
		if (first == NULL)
			first = last;
		i++;
	}
	if (check_double_nums(first) || i < 1)
	{
		print_error();
		free_temp(temp);
		free_list(&first, &last);
		return (NULL);
	}
	free_temp(temp);
	return (first);
}

t_node	*stack_a(int argc, char *argv[])
{
	t_node	*first;
	t_node	*last;
	int		i;

	first = NULL;
	last = NULL;
	i = 1;
	while (i < argc)
	{
		add_list(&last, ft_atoi(argv[i]));
		if (first == NULL)
			first = last;
		i++;
	}
	if (check_double_nums(first))
	{
		print_error();
		free_list(&first, &last);
		return (NULL);
	}
	return (first);
}
