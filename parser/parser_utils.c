/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:13:34 by admin             #+#    #+#             */
/*   Updated: 2026/01/21 11:45:28 by admin            ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	n;
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	n = ft_strlen(dst);
	j = ft_strlen(src);
	if (dstsize <= n)
		return (dstsize + j);
	if (j > (dstsize - n - 1))
		k = dstsize - n - 1;
	else
		k = j;
	while (i < k)
	{
			dst[n + i] = src[i];
			i++;
	}
	dst[n + i] = '\0';
	return (n + j);
}

char	*ft_strjoin(int argc, char **argv)
{
	int	len;
	int	len1;
	int	i;
	char	*strjoin;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]) + 1;
		i++;
	}
	printf("size being allocated: %d\n", len);
	strjoin = (char *)ft_calloc(len, sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	i = 1;
	len1 = 0;
	while (i < argc)
	{
		len1 += ft_strlen(argv[i]);
		ft_strlcat(strjoin, argv[i], len);
		i++;
		if (i == argc)
			break;
		strjoin[len1] = ' ';
		len1++;
	}
	return (strjoin);
}
