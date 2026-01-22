/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:05:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/22 18:35:09 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (str[1] < '0' || str[1] > '9')
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int	i;
	long	num;
	long	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + ((char)str[i] - '0');
		i++;
	}
	return (sign * num);
}

int	check_duplicates_and_limits(long *array_of_numbers, int size_of_array)
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

t_list	*create_node(int num)
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

void	insert_node_at_end(t_list **head_of_my_list, t_list **end_of_my_list, int num)
{
	t_list	*temp;

	t_list	*new_node = create_node(num);
	if (!(*head_of_my_list))
	{
		*head_of_my_list = new_node;
		*end_of_my_list = new_node;
	}
	else
	{
		temp = *head_of_my_list;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new_node;
		temp -> next -> previous = temp;
	}
	*end_of_my_list = new_node;
}
t_stack	*parser(int argc, char **argv)
{
	char	*concatenated_string_of_numbers;
	char	**split_string_of_numbers;
	char	separator;
	int		i;
	int		j;
	long	*array_of_longs;
	t_list	*head_of_my_list;
	t_list	*end_of_my_list;
	t_stack	*stack_a;
	
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	separator = ' ';
	concatenated_string_of_numbers = ft_strjoin(argc, argv);
	split_string_of_numbers = ft_split(concatenated_string_of_numbers, separator);

	i = 0;
	while (split_string_of_numbers[i])
	{
		if (is_valid_number(split_string_of_numbers[i]) == 0)
			return (free_all(split_string_of_numbers, i), NULL);
		i++;
	}
	array_of_longs = ft_calloc(i, sizeof(long));
	if (!array_of_longs)
		return (free_all(split_string_of_numbers, i), NULL);
	j = 0;
	while (j < i)
	{
		array_of_longs[j] = ft_atoi(split_string_of_numbers[j]);
		free(split_string_of_numbers[i]);
		split_string_of_numbers[i] = NULL;
		j++;
	}
	free(split_string_of_numbers);
	split_string_of_numbers = NULL;
	if (check_duplicates_and_limits(array_of_longs, i) == 1)
		return (free(array_of_longs), array_of_longs = NULL, NULL);
	j = 0;
	head_of_my_list = NULL;
	end_of_my_list = NULL;
	while (j < i)
	{
		insert_node_at_end(&head_of_my_list, &end_of_my_list, array_of_longs[j]);
		j++;
	}
	stack_a -> head = head_of_my_list;
	stack_a -> end = end_of_my_list;
	return (stack_a);
}

