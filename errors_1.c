/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:20:31 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/15 18:44:27 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_inputs(char *argv)
{
	int	j;

	j = 0;
	if (!argv || argv[0] == '\0')
		return (0);
	if (check_space(argv[j]))
		return (0);
	while (argv[j])
	{
		while (argv[j] && check_space(argv[j]))
			j++;
		if (argv[j] && check_sign(argv[j]))
			j++;
		if (!argv[j] && !ft_isdigit(argv[j]))
			return (0);
		while (argv[j] && ft_isdigit(argv[j]))
			j++;
		if (argv[j] && !check_space(argv[j]))
			return (0);
	}
	return (1);
}

int	input_check(char *argv[])
{
	int	i;
	int	j;
	int	space;

	i = 1;
	while (argv[i])
	{
		space = 0;
		if (argv[i][0] == '\0' || !valid_inputs(argv[i]))
			return (0);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
				space = 1;
			j++;
		}
		if (space && i > 1)
			return (0);
		i++;
	}
	return (1);
}

int	double_space_check(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (check_space(argv[i][j]) && check_space(argv[i][j + 1]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_double_nums(t_node *a)
{
	t_node	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->x == temp->x)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}
