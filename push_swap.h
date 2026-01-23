/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:40 by admin             #+#    #+#             */
/*   Updated: 2026/01/23 19:21:07 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	long			number;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_task
{
	t_list	*head;
	t_list	*tail;
}	t_stack;

// MAIN FUNCTION //
t_stack	*parser(int argc, char **argv);
void	turk_sort(t_list **stack_a);

// PARSER FUNCTION //
char	*ft_strjoin(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		is_valid_number(char **split_string, int words_count);
long	*ft_atoi(char **split_string, int words_count);
int		find_duplicates_and_limits(long *array_of_numbers, int size_of_array);
t_list	*create_node(long num);
t_stack	*create_stack(long *array_of_longs, int size);

// SPLIT FUNCTION FOR PARSER //
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		free_all(char **result, int word);
int		numwords(char const *s, char c);
int		split_words(char **result, char *s, char c, int word);
char	**ft_split(char *s, char c);

#endif