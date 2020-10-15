/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 20:05:56 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/21 20:23:58 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*output;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!(output = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while ((char)s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*tmp)
			tmp++;
		return ((char *)tmp);
	}
	while (tmp[i] != '\0')
	{
		if (tmp[i] == (char)c)
			return ((char *)&tmp[i]);
		i++;
	}
	if (*tmp == '\0' && c == '\0')
		return (tmp);
	return (NULL);
}

char	*ft_strsub(char *str, int start, int len)
{
	int		i;
	char	*output;

	i = 0;
	if (!str)
		return (NULL);
	if (!(output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (str[start + i] != '\n'))
	{
		output[i] = str[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned long	i;
	unsigned long	size1;
	unsigned long	size2;

	if (!(s1 && s2))
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!(output = malloc(sizeof(char) * (size1 + size2 + 1))))
		return (NULL);
	i = 0;
	while (i < size1)
	{
		output[i] = s1[i];
		i++;
	}
	while (i < (size1 + size2))
	{
		output[i] = s2[i - size1];
		i++;
	}
	output[i] = '\0';
	return (output);
}
