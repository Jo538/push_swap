/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:05:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/22 17:00:35 by admin            ###   ########.fr       */
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

int	check_duplicates(int *array_of_numbers, int size_of_array)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_of_array)
	{
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

t_list *insert_node_at_end(t_list **head_of_my_list, int num)
{
	t_list	*temp;
	t_list	*end;

	t_list	*new_node = create_node(num);
	if (!(*head_of_my_list))
		*head_of_my_list = new_node;
	else
	{
		temp = *head_of_my_list;
		while (temp -> next)
			temp = temp -> next;
		temp -> next = new_node;
		temp -> next -> previous = temp;
	}
	end = new_node;
	return (end);
}
t_list	**parser(int argc, char **argv)
{
	char	*concatenated_string_of_numbers;
	char	**split_string_of_numbers;
	char	separator;
	int		i;
	int		j;
	long	*array_of_longs;
	
	separator = ' ';
	concatenated_string_of_numbers = ft_strjoin(argc, argv);
	split_string_of_numbers = ft_split(concatenated_string_of_numbers, separator);

	i = 0;
	while (split_string_of_numbers[i])
	{
		if (is_valid_number(split_string_of_numbers[i]) == 0)
			return (NULL);
		i++;
	}
	array_of_longs = ft_calloc(i, sizeof(long));
	if (!array_of_longs)
		return (NULL);
	j = 0;
	while (j < i)
	{
		array_of_longs[j] = ft_atoi(split_string_of_numbers[j]);
		printf("number %d: %ld\n", j, array_of_longs[j]);
		j++;
	} 
	
	return (NULL);
	
// add a part to check if number is or is not an int	
}