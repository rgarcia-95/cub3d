/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:59:58 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 20:00:29 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (dst != 0 || src != 0)
	{
		while (src[size] != '\0')
			size++;
		if (dstsize > 0)
		{
			while (i < (dstsize - 1) && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (size);
	}
	return (0);
}

static int	ft_num_w(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static char	*ft_malloc(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		num_w;
	char	**str;

	if (s == 0)
		return (0);
	i = -1;
	num_w = ft_num_w(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (num_w + 1))))
		return (0);
	while (++i < num_w)
	{
		while (*s == c)
			s++;
		if (!(str[i] = ft_malloc(s, c)))
		{
			while (i > 0)
				free(str[i--]);
			free(str);
			return (0);
		}
		s += ft_strlen(str[i]);
	}
	str[i] = 0;
	return (str);
}
