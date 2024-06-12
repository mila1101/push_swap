/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:08:33 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/07 14:39:33 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	space_skip(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	return (i);
}

static int	to_int(const char *str, int i)
{
	long long	sign;
	long long	num;

	sign = 1;
	num = 0;
	if (str[i] == '-')
	{
		sign = -1;
		num = -num;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num = num * sign;
	if (num > INT_MAX || num < INT_MIN)
	{
		print_error();
		return (0);
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = space_skip(str);
	num = to_int(str, i);
	return (num);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			temp;
	unsigned char	*a;
	size_t			i;

	i = 0;
	temp = count * size;
	if (count && size && (temp / count != size))
		return (NULL);
	ptr = malloc(temp);
	if (!ptr)
		return (NULL);
	a = ptr;
	while (i < temp)
	{
		a[i] = 0;
		i++;
	}
	return (ptr);
}
