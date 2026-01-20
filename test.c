/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:34:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/20 12:32:10 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>

int	main(void)
{
	char *result = NULL;
	int argc = 3;
	char **argv = NULL;
	argv = ft_calloc(argc + 1, sizeof(char *));
	argv[0] = "./a.out";
	argv[1] = "1";
	argv[2] = "2";
	argv[3] = NULL;

	result = ft_strjoin(argc, argv);
	printf("%s\n", result);
}