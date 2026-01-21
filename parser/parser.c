/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:05:00 by admin             #+#    #+#             */
/*   Updated: 2026/01/21 17:13:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-')
			&& (str[i + 1] < 0 || str[i + 1] > 9))
			return (0);
		i++;
	}
	return (1);
}


// t_list	*parser(int argc, char **argv)
// {
// 	char	*concatenated_string;
	
// 	concatenated_string = ft_strjoin(argc, argv);
	
	
// }