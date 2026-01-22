/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/22 17:02:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>

int	main(void)
{
	#ifdef FT_STRJOIN_TEST

	char *result = NULL;
	int argc = 4;
	char **argv = NULL;
	argv = ft_calloc(argc + 1, sizeof(char *));
	argv[0] = "./a.out";
	argv[1] = "one";
	argv[2] = "25 30";
	argv[3] = "3";
	// argv[4] = "4";
	argv[5] = NULL;

	result = ft_strjoin(argc, argv);
	printf("%s\n", result);

	#endif
	
	#ifdef IS_VALID_NUMBER_TEST

	char *string = "-+24";
	int result = is_valid_number(string);
	printf("%d\n", result);
	
	#endif

	#ifdef FT_SPLIT_TEST

	char *string_to_split = "1 one 2";
	char separator = ' ';
	char **result = ft_split(string_to_split, separator);
	int i = 0;
	while (result[i])
	{
		printf("number %d: %s\n", i, result[i]);
		i++;
	}

	#endif

	#ifdef FT_ATOI_TEST

	char *str = "1";
	long result = ft_atoi(str);
	printf("%ld\n", result);
	
	#endif

	#ifdef CHECK_DUPLICATES_TEST

	int array_of_numbers[] = {0, 1, 2, 1, 5};
	int size_of_array = 5;
	int result;
	
	result = check_duplicates(array_of_numbers, size_of_array);
	if (result == 1)
		printf("%s\n", "Error: there are some duplicates in the list.");
	else
		printf("%s\n", "OK: there are no duplicates in the list.");
	#endif

	#ifdef CREATE_NODE_TEST

	int num = 25;
	t_list *node = create_node(num);
	printf("previous: %p\n", node -> previous);
	printf("next: %p\n", node -> next);
	printf("number: %d\n", node -> number);
	
	#endif

	#ifdef INSERT_NODE_AT_END_TEST

	t_list *head_of_my_list = NULL;
	t_list *temp_from_head;
	int num1 = 42;
	int num2 = 36;
	
	t_list *temp_from_end = insert_node_at_end(&head_of_my_list, num1);
	temp_from_end = insert_node_at_end(&head_of_my_list, num2);
	temp_from_head = head_of_my_list;
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %d\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	while (temp_from_end)
	{
		printf("address of this node: %p\n", temp_from_end);	
		printf("previous: %p\n", temp_from_end -> previous);
		printf("number: %d\n", temp_from_end -> number);
		printf("next: %p\n\n", temp_from_end -> next);
		temp_from_end = temp_from_end -> previous;
	}
	#endif

	#ifdef PARSER_TEST

	// char *result = NULL;
	int argc = 4;
	char **argv = NULL;
	argv = ft_calloc(argc + 1, sizeof(char *));
	argv[0] = "./a.out";
	argv[1] = "1";
	argv[2] = "+25 -30";
	argv[3] = "-2147483649";
	// argv[4] = "4";
	argv[5] = NULL;
	
	parser(argc, argv);

	#endif
}