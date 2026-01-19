/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:13:34 by admin             #+#    #+#             */
/*   Updated: 2026/01/19 19:00:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	free_all(int **result, int number)
// {
// 	while (result[number - 1] && result)
// 	{
// 		free(result[number]);
// 		number--;
// 	}
// 	free(result);
// 	return (0);
// }

int	count_ints(char const *s, char c)
{
	int	cur;
	int	ints_num;

	cur = 0;
	ints_num = 0;
	while (s[cur] != 0)
	{
		if (s[cur] != c && (s[cur + 1] == c || s[cur + 1] == 0))
			ints_num++;
		cur++;
	}
	return (ints_num);
}

// static int	split_ints(int **result, char const *s, char c, int number)
// {
// 	int	start_cur;
// 	int	end_cur;

// 	end_cur = 0;
// 	start_cur = 0;
// 	while (s[end_cur])
// 	{
// 		if (s[end_cur] == c || s[end_cur] == 0)
// 			start_cur = end_cur + 1;
// 		if (s[end_cur] != c && (s[end_cur + 1] == c || s[end_cur + 1] == 0))
// 		{
// 			result[number] = malloc(sizeof(char) * (end_cur - start_cur + 2));
// 			if (!result[number])
// 				return (free_all(result, number));
// 			ft_strlcpy(result[number], (s + start_cur), end_cur - start_cur + 2);
// 			number++;
// 		}
// 		end_cur++;
// 	}
// 	result[number] = 0;
// 	return (1);
// }

// int	**ft_split(char const *s, char c)
// {
// 	int	**result;

// 	if (!s)
// 		return (NULL);
// 	result = malloc(sizeof(int *) * (count_ints(s, c) + 1));
// 	if (!result)
// 		return (NULL);
// 	if (!split_ints(result, s, c, 0))
// 		return (NULL);
// 	return (result);
// }
