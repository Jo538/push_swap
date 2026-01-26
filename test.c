/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/26 11:20:52 by jchartie         ###   ########.fr       */
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

	int argc = 4;
	char **argv = NULL;
	argv = ft_calloc(argc, sizeof(char *));
	argv[0] = "-1";
	argv[1] = "-25";
	argv[2] = "3";
	argv[3] = NULL;

	int result = is_valid_number(argv, argc - 1);
	printf("Result: %d\n", result);
	
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

	char *test_strings[] = {"-1", "-25", "3", "2147483647", "-2147483649"};
	int count = 5;
	int i = 0;
	long	*result;
	char **argv = ft_calloc(count + 1, sizeof(char *));
	
	// Allocate and copy each string
	while (i < count)
	{
		int len = 0;
		while (test_strings[i][len])
			len++;
		argv[i] = ft_calloc(len + 1, sizeof(char));
		int j = 0;
		while (j <= len)
		{
			argv[i][j] = test_strings[i][j];
			j++;
		}
		i++;
	}
	argv[count] = NULL;
	
	// Test ft_atoi on each string
	i = 0;
	result = ft_atoi(argv, count);
	while (i < count)
	{
		printf("Number: %ld\n", result[i]);
		i++;
	}
	
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

	#ifdef CREATE_STACK_TEST

	t_list *temp_from_head;
	t_list *temp_from_end;
	
	long list_of_longs[] = {-1, 42, 36};
	int len = 3;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	t_stack *stack = create_stack(array_of_longs);
	
	free(array_of_longs);
	
	temp_from_head = stack -> head;
	temp_from_end = stack -> tail;
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
	argv[2] = "-1 35";
	argv[3] = "-2147483648";
	argv[4] = NULL;  // Fixed: was argv[5]
	
	t_stack *stack_a = parser(argc, argv);
	t_list *temp_from_head = stack_a -> head;
	t_list *temp_from_end = stack_a -> tail;
	
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %d\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %d\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	printf("\n=== Traversing from tail ===\n\n");
	
	while (temp_from_end)
	{
		printf("address of this node: %p\n", temp_from_end);	
		printf("previous: %p\n", temp_from_end -> previous);
		printf("number: %d\n", temp_from_end -> number);
		printf("next: %p\n\n", temp_from_end -> next);
		temp_from_end = temp_from_end -> previous;
	}
	
	// Free the linked list properly
	temp_from_head = stack_a -> head;
	while (temp_from_head)
	{
		t_list *next = temp_from_head -> next;
		free(temp_from_head);
		temp_from_head = next;
	}
	
	free(stack_a);
	free(argv);
	}	
	#endif

	#ifdef SWAP_A_TEST

	t_list *temp_from_head;
	t_list *temp_from_end;
	
	long list_of_longs[] = {};
	int len = 0;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	t_stack *stack = create_stack(array_of_longs, len);
	
	// free(array_of_longs);
	
	temp_from_head = stack -> head;
	temp_from_end = stack -> tail;
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %ld\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	swap_a(&(stack -> head));

	printf("%s\n\n", "List after the swap");
	temp_from_head = stack -> head;
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %ld\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	while (temp_from_end)
	{
		printf("address of this node: %p\n", temp_from_end);	
		printf("previous: %p\n", temp_from_end -> previous);
		printf("number: %ld\n", temp_from_end -> number);
		printf("next: %p\n\n", temp_from_end -> next);
		temp_from_end = temp_from_end -> previous;
	}

	#endif

	#ifdef PUSH_TEST

	t_list *temp_from_head_a;
	t_list *temp_from_end_a;
	t_list *temp_from_head_b;
	t_list *temp_from_end_b;	

	
	long list_of_longs_a[] = {1, 2, 3, 4};
	int len_a = 4;

	long list_of_longs_b[] = {5, 6, 7};
	int len_b = 3;
	
	long *array_of_longs_a = ft_calloc(len_a, sizeof(long));
	long *array_of_longs_b = ft_calloc(len_b, sizeof(long));

	int i = 0;
	while (i < len_a)
	{
		array_of_longs_a[i] = list_of_longs_a[i];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		array_of_longs_b[i] = list_of_longs_b[i];
		i++;
	}
	
	t_stack *stack_a = create_stack(array_of_longs_a, len_a);
	t_stack *stack_b = create_stack(array_of_longs_b, len_b);
	
	// free(array_of_longs);
	
	temp_from_head_a = stack_a -> head;
	temp_from_end_a = stack_a -> tail;
	temp_from_head_b = stack_b -> head;
	temp_from_end_b = stack_b -> tail;	

	printf("%s\n\n", "List before the push");
	printf("%s\n\n", "STACK_A");
	while (temp_from_head_a)
	{
		printf("address of this node: %p\n", temp_from_head_a);
		printf("previous: %p\n", temp_from_head_a -> previous);
		printf("number: %ld\n", temp_from_head_a -> number);
		printf("next: %p\n\n", temp_from_head_a -> next);
		temp_from_head_a = temp_from_head_a -> next;
	}

	printf("\n\n%s\n\n", "STACK_B");
	
	while (temp_from_head_b)
	{
		printf("address of this node: %p\n", temp_from_head_b);
		printf("previous: %p\n", temp_from_head_b -> previous);
		printf("number: %ld\n", temp_from_head_b -> number);
		printf("next: %p\n\n", temp_from_head_b -> next);
		temp_from_head_b = temp_from_head_b -> next;
	}

	
	push(&(stack_a -> head), &(stack_b -> head));

	printf("\n\n%s\n\n", "List after the push");

	temp_from_head_a = stack_a -> head;
	temp_from_head_b = stack_b -> head;

	printf("%s\n\n", "STACK_A");
	
	while (temp_from_head_a)
	{
		printf("address of this node: %p\n", temp_from_head_a);
		printf("previous: %p\n", temp_from_head_a -> previous);
		printf("number: %ld\n", temp_from_head_a -> number);
		printf("next: %p\n\n", temp_from_head_a -> next);
		temp_from_head_a = temp_from_head_a -> next;
	}

	while (temp_from_end_a)
	{
		printf("address of this node: %p\n", temp_from_end_a);	
		printf("previous: %p\n", temp_from_end_a -> previous);
		printf("number: %ld\n", temp_from_end_a -> number);
		printf("next: %p\n\n", temp_from_end_a -> next);
		temp_from_end_a = temp_from_end_a -> previous;
	}

	printf("%s\n\n", "STACK_B");
	
	while (temp_from_head_b)
	{
		printf("address of this node: %p\n", temp_from_head_b);
		printf("previous: %p\n", temp_from_head_b -> previous);
		printf("number: %ld\n", temp_from_head_b -> number);
		printf("next: %p\n\n", temp_from_head_b -> next);
		temp_from_head_b = temp_from_head_b -> next;
	}

	while (temp_from_end_b)
	{
		printf("address of this node: %p\n", temp_from_end_b);	
		printf("previous: %p\n", temp_from_end_b -> previous);
		printf("number: %ld\n", temp_from_end_b -> number);
		printf("next: %p\n\n", temp_from_end_b -> next);
		temp_from_end_b = temp_from_end_b -> previous;
	}

	#endif

	
	#ifdef ROTATE_TEST

	t_list *temp_from_head;
	t_list *temp_from_end;
	
	long list_of_longs[] = {1, 2, 3, 4};
	int len = 4;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	t_stack *stack = create_stack(array_of_longs, len);
	
	// free(array_of_longs);
	
	temp_from_head = stack -> head;
	temp_from_end = stack -> tail;

	printf("%s\n\n", "List BEFORE the rotation");	
	
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %ld\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	rotate(&stack);

	printf("\n\n%s\n\n", "List after the rotation");

	printf("\n\n%s\n\n", "FROM HEAD");
	
	temp_from_head = stack -> head;
	while (temp_from_head)
	{
		printf("address of this node: %p\n", temp_from_head);
		printf("previous: %p\n", temp_from_head -> previous);
		printf("number: %ld\n", temp_from_head -> number);
		printf("next: %p\n\n", temp_from_head -> next);
		temp_from_head = temp_from_head -> next;
	}

	printf("\n\n%s\n\n", "FROM TAIL");

	temp_from_end = stack -> tail;
	while (temp_from_end)
	{
		printf("address of this node: %p\n", temp_from_end);	
		printf("previous: %p\n", temp_from_end -> previous);
		printf("number: %ld\n", temp_from_end -> number);
		printf("next: %p\n\n", temp_from_end -> next);
		temp_from_end = temp_from_end -> previous;
	}

	#endif
}