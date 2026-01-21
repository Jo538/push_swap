/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/21 12:09:24 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>

int	main(void)
{
	char *result = NULL;
	int argc = 4;
	char **argv = NULL;
	argv = ft_calloc(argc + 1, sizeof(char *));
	argv[0] = "./a.out";
	argv[1] = "1";
	argv[2] = "25 30";
	argv[3] = "3";
	// argv[4] = "4";
	argv[5] = NULL;

	result = ft_strjoin(argc, argv);
	printf("%s\n", result);
}