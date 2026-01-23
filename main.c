/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/01/23 19:10:02 by admin            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_list	*temp;

	if (argc == 1) // case where no argument is passed at execution time
		return (-1);
	stack_a = parser(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	temp = stack_a -> head;
	while (temp)
	{
		printf("%ld\n", temp -> number);
		temp = temp -> next;
	}
// 	turk_sort(stack_a);
	return (0);
}