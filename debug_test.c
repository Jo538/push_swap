/* Debug test to trace the algorithm */
#include "push_swap.h"
#include <stdio.h>

void print_stacks(t_stack *a, t_stack *b, char *msg)
{
	t_list *temp;
	int i;
	
	printf("\n=== %s ===\n", msg);
	printf("Stack A: ");
	temp = a->head;
	while (temp)
	{
		printf("%ld ", temp->number);
		temp = temp->next;
	}
	printf("\nStack B: ");
	if (b->head)
	{
		temp = b->head;
		while (temp)
		{
			printf("%ld ", temp->number);
			temp = temp->next;
		}
	}
	else
	{
		printf("(empty)");
	}
	printf("\n");
}

int main(void)
{
	long list_of_longs[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
	int len = 9;
	long *array_of_longs = ft_calloc(len, sizeof(long));
	int i = 0;
	while (i < len)
	{
		array_of_longs[i] = list_of_longs[i];
		i++;
	}
	
	t_stack *stack_a = create_stack(array_of_longs, len);
	t_stack *stack_b = ft_calloc(1, sizeof(t_stack));

	print_stacks(stack_a, stack_b, "INITIAL");

	// Push first 2 to B
	push(&stack_b, &stack_a, 'B');
	push(&stack_b, &stack_a, 'B');
	print_stacks(stack_a, stack_b, "After 2 pushes to B");

	// Continue until 3 left in A
	int size_a = size_stack(stack_a);
	while (size_a > 3)
	{
		t_pair *array = compute_pairs(stack_a, stack_b, 'B');
		int min = find_cheapest(array, size_a);
		move_to_top(&stack_a, &stack_b, array, min);
		push(&stack_b, &stack_a, 'B');
		free(array);
		size_a--;
	}
	
	print_stacks(stack_a, stack_b, "Before sort_three");
	sort_three(&stack_a);
	print_stacks(stack_a, stack_b, "After sort_three");

	// Push back from B to A
	int size_b = size_stack(stack_b);
	i = 0;
	while (i < size_b)
	{
		t_pair *array = compute_pairs(stack_b, stack_a, 'A');
		int min = find_cheapest(array, size_b - i);
		
		t_list *temp = stack_b->head;
		int j = 0;
		while (j < min && temp)
		{
			temp = temp->next;
			j++;
		}
		
		if (!temp) {
			printf("\nERROR: temp is NULL at min=%d\n", min);
			break;
		}
		
		t_list *temp_debug = stack_a->head;
		printf("\n=== Iteration %d ===\n", i);
		printf("Stack A before move_to_top: ");
		while (temp_debug) {
			printf("%ld ", temp_debug->number);
			temp_debug = temp_debug->next;
		}
		printf("\n");
		
		printf("Pushing B[%d]=%ld to A, target index in A: %d\n", 
			min, temp->number, array[min].target_index);
		
		move_to_top(&stack_b, &stack_a, array, min);
		
		temp_debug = stack_a->head;
		printf("Stack A after move_to_top: ");
		while (temp_debug) {
			printf("%ld ", temp_debug->number);
			temp_debug = temp_debug->next;
		}
		printf("\n");
		
		push(&stack_a, &stack_b, 'A');
		print_stacks(stack_a, stack_b, "After push to A");
		free(array);
		i++;
	}

	// Final rotation
	final_rotation(&stack_a);
	print_stacks(stack_a, stack_b, "FINAL");
	
	return 0;
}
