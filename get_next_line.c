/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:37:38 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 17:03:52 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	str_free(char *str, int i)
{
	free(str);
	return (i);
}

static int	ft_read(int fd, char **temp)
{
	int		ret;
	int		check;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	ret = 1;
	check = 1;
	while ((ret > 0) && check == 1)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
			return (-1);
		buffer[ret] = '\0';
		if (*temp)
		{
			tmp = ft_strdup(*temp);
			free(*temp);
			*temp = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		else
			*temp = ft_strdup(buffer);
		check = ((ft_strchr(buffer, '\n')) ? 0 : 1);
	}
	return (ret);
}

static char	*ft_find_nl(char **temp)
{
	char	*memory;
	char	*stock_long;

	memory = NULL;
	stock_long = ft_strdup((char *)temp);
	if (ft_strchr(*temp, '\n'))
	{
		free(stock_long);
		stock_long = NULL;
		stock_long = ft_strsub(*temp, 0, (ft_strlen(*temp)
		- ft_strlen(ft_strchr(*temp, '\n'))));
		memory = ft_strdup(ft_strchr(*temp, '\n') + 1);
		free(*temp);
		*temp = NULL;
		*temp = (char *)ft_strdup(stock_long);
	}
	free(stock_long);
	return (memory);
}

static char	*ft_join_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = ft_strjoin(s2, tmp);
	free(tmp);
	free(s2);
	s2 = NULL;
	return (s1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		*temp;
	static char	*memory;

	temp = ft_strdup("\0");
	ret = ft_read(fd, &temp);
	if (ret < 0 || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (str_free(temp, -1));
	temp = (memory != NULL) ? ft_join_free(temp, memory) : temp;
	memory = NULL;
	if ((ret == 0 && !ft_strchr(temp, '\n') && !ft_strchr(memory, '\n')))
	{
		*line = ft_strdup(temp);
		return (str_free(temp, 0));
	}
	if (ret >= 0)
	{
		memory = ft_find_nl(&temp);
		*line = ft_strdup(temp);
	}
	return (str_free(temp, 1));
}
