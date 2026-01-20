/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchartie <jchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:13:34 by admin             #+#    #+#             */
/*   Updated: 2026/01/20 12:34:41 by jchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	if (count != 0 && size > ((size_t) - 1) / count)
		return (NULL);
	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)memory)[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strjoin(int argc, char **argv)
{
	int	len;
	int	i;
	char	*strjoin;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	strjoin = (char *)ft_calloc((len + 2), sizeof(char));
	if (strjoin == NULL)
		return ( NULL);
	// i = 0;
	// while (i < len1)
	// {
	// 	strjoin[i] = s1[i];
	// 	i++;
	// }
	// strjoin[i++] = ' ';
	// while (i < len1 + len2 + 1)
	// {
	// 	strjoin[i] = s2[i - len1 - 1];
	// 	i++;
	// }
	// strjoin[i] = '\0';
	// // free(s1);
	return (strjoin);
}
