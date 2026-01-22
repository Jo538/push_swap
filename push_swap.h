/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:46:40 by admin             #+#    #+#             */
/*   Updated: 2026/01/22 17:22:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

// MAIN FUNCTION //
t_list	**parser(int argc, char **argv);
void	turk_sort(t_list **stack_a);

// PARSER FUNCTION //
char	*ft_strjoin(int argc, char **argv);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	is_valid_number(char *str);
long	ft_atoi(const char *str);
int	check_duplicates(long *array_of_numbers, int size_of_array);
t_list	*create_node(int num);
t_list *insert_node_at_end(t_list **head_of_my_list, int num);

// SPLIT FUNCTION FOR PARSER //
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	free_all(char **result, int word);
int	numwords(char const *s, char c);
int	split_words(char **result, char const *s, char c, int word);
char	**ft_split(char const *s, char c);

#endif