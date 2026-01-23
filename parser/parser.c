/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:05:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/23 18:32:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_number(char **split_string, int words_count)
{
	int	i;
	int	j;

	i = 0;
	while (split_string[i])
	{
		j = 0;
		if (split_string[i][0] == '+' || split_string[i][0] == '-')
		{
			j++;
			if (split_string[i][1] < '0' || split_string[i][1] > '9')
				return (free_all(split_string, words_count), 0);
		}
		while (split_string[i][j])
		{
			if (split_string[i][j] < '0' || split_string[i][j] > '9')
				return (free_all(split_string, words_count), 0);
			j++;
		}
		i++;
	}
	return (1);
}

long	*ft_atoi(char **split_string, int words_count)
{
	int	i;
	int	j;
	long	num;
	long	sign;
	long	*array_of_longs;

	i = 0;
	array_of_longs = ft_calloc(words_count, sizeof(long));
	if (!array_of_longs)
		return (free_all(split_string, words_count), NULL);
	while (split_string[i])
	{
		j = 0;
		num = 0;
		sign = 1;
		if (split_string[i][0] == '-')
			sign = -1;
		if (split_string[i][0] == '-' || split_string[i][0] == '+')
			j++;
		while (split_string[i][j] >= '0' && split_string[i][j] <= '9')
			num = 10 * num + ((char)split_string[i][j++] - '0');
		array_of_longs[i] = sign * num;
		free(split_string[i++]);
	}
	return (free(split_string), array_of_longs);
}

int	find_duplicates_and_limits(long *array_of_numbers, int size_of_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_of_array)
	{
		if (array_of_numbers[i] < INT_MIN || array_of_numbers[i] > INT_MAX)
			return (1);
		j = 1;
		while (j < (size_of_array - i))
		{
			if (array_of_numbers[i] == array_of_numbers[i + j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*create_node(long num)
{
	t_list	*new_node;
	
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> previous = NULL;
	new_node -> next = NULL;
	new_node -> number = num;
	return (new_node);
}

t_stack	*create_stack(long *array_of_longs, int size)
{
	t_list	*temp;
	t_list	*new_node;
	t_stack	*stack;
	int	i;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	new_node = create_node(array_of_longs[0]);
	stack -> head = new_node;
	i = 1;
	while (i < size)
	{
		new_node = create_node(array_of_longs[i]);
		temp = stack -> head;
			while (temp -> next)
				temp = temp -> next;
		temp -> next = new_node;
		temp -> next -> previous = temp;
		i++;
	}
	stack -> tail = new_node;
	return (stack);
}

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
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

