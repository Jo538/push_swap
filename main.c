/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:48 by admin             #+#    #+#             */
/*   Updated: 2026/01/21 13:57:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;

	if (argc == 1) // case where no argument is passed at execution time
		return ;
	stack_a = parser(argc, argv);
	turk_sort(stack_a);
}