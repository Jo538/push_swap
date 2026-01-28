/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/01/28 20:37:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parser(int argc, char **argv)
{
	char	*concatenated_string;
	char	**split_string;
	int		i;
	long	*array_of_longs;
	t_stack	*stack_a;

	concatenated_string = ft_strjoin(argc, argv);
	if (!concatenated_string)
		return (NULL);
	split_string = ft_split(concatenated_string, ' ');
	if (!split_string)
		return (NULL);
	i = 0;
	while (split_string[i])
		i++;
	if (is_valid_number(split_string, i) == 0)
		return (NULL);
	array_of_longs = ft_atoi(split_string, i);
	if (!array_of_longs)
		return (NULL);
	if (find_duplicates_and_limits(array_of_longs, i) == 1)
		return (free(array_of_longs), NULL);
	stack_a = create_stack(array_of_longs, i);
	return (stack_a);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_pair	*array;
	int		min;
	int		size_a;
	int		size_b;
	int		i;

	// go back to this later on
	if (is_sorted(*stack_a) == 1)
		return ;

	// Start by pushing the first 2 elements of A to B
	push(stack_b, stack_a, 'B');
	push(stack_b, stack_a, 'B');

	// Repeat this process until there are only 3 numbers left in STACK A
	size_a = size_stack(*stack_a);
	while (size_a > 3)
	{
		// Create the array of pairs (b_tar, all_cost). 
		// The array size is count of numbers in stack a
		array = compute_pairs(*stack_a, *stack_b, 'B');
		
		// Find cheapest pair
		min = find_cheapest(array, size_a);

		// Move up chosen pair, cheapest one
		move_to_top(stack_a, stack_b, array, min, 'B');

		// Push A to B
		push(stack_b, stack_a, 'B');
		free(array);
		size_a--;
	}
	
	// Sort the last 3 numbers in A
	sort_three(stack_a);

	// Find size_b to create loop

	i = 0;
	size_b = size_stack(*stack_b);
	while (i < size_b)
	{
		// Create the array of pairs (b_tar, all_cost). 
		// The array size is count of numbers in stack b
		array = compute_pairs(*stack_b, *stack_a, 'A');
		
		// Find cheapest pair
		int current_size_b = size_stack(*stack_b);
		min = find_cheapest(array, current_size_b);

		// Move up chosen pair, cheapest one
		move_to_top(stack_b, stack_a, array, min, 'A');

		// Push B to A
		push(stack_a, stack_b, 'A');
		free(array);
		i++;
	}
	
	// Final rotation: move minimum to top of stack A
	final_rotation(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (-1);
	
	stack_a = parser(argc, argv);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!stack_b)
		return (-1);
	
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	
	turk_sort(&stack_a, &stack_b);
	
	return (0);
}
