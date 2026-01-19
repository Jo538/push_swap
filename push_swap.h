/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:40 by admin             #+#    #+#             */
/*   Updated: 2026/01/19 19:01:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

// typedef struct s_list
// {
// 	int				data;
// 	struct s_list	*next;
// 	struct s_list	*previous;
// }	t_list;

// t_list	*parser(int argc, char **argv);
// void	turk_sort(t_list **stack_a);
// char	**ft_split(char const *s, char c);
// static int	split_ints(int **result, char const *s, char c, int word);
int	count_ints(char const *s, char c);
// static int	free_all(int **result, int word);

#endif