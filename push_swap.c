/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:21:10 by msoklova          #+#    #+#             */
/*   Updated: 2024/06/16 14:49:42 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	s_print(t_node *stack)
//{
//	t_node	*temp;

//	temp = stack;
//	while (temp != NULL)
//	{
//		printf("%lld ", temp->x);
//		temp = temp->next;
//	}
//	printf("\n");
//}

void	sort_type(t_node **stack_a, t_node **stack_b, int i)
{
	t_node	*a_stack;
	t_node	*b_stack;

	a_stack = *stack_a;
	b_stack = *stack_b;
	if (!sorted_stack(a_stack))
	{
		if (i == 2)
			sa(&a_stack);
		else if (i == 3)
			sort_three(&a_stack);
		else if (i == 4)
			sort_four(&a_stack, &b_stack);
		else if (i == 5)
			sort_five(&a_stack, &b_stack);
		else if (i > 5)
			radix_sort(&a_stack, &b_stack);
	}
}

static void	get_stack(t_node **a, t_node **b, int argc, char *argv[])
{
	int	i;

	if (argc == 2)
		*a = quoted_stack(argv);
	else if (argc > 2)
		*a = stack_a(argc, argv);
	else
		return ;
	i = node_counter(*a);
	give_index(*a);
	sort_type(a, b, i);
}

int	main(int argc, char *argv[])
{
	t_node	*a_stack;
	t_node	*b_stack;

	if (!argv[1])
		return (1);
	b_stack = NULL;
	if (input_check(argv) && double_space_check(argv))
	{
		if (argc == 2 && argv[1][0] == '\0')
			return (0);
		get_stack(&a_stack, &b_stack, argc, argv);
	}
	else
		print_error();
	free_final_stack(&a_stack);
	return (0);
}
