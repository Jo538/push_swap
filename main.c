/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/01/23 18:42:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == 1) // case where no argument is passed at execution time
		return ;
	stack_a = parser(argc, argv);
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return ;
	}
	turk_sort(stack_a);
}