/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:47:06 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:47:36 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_without_spaces(char *buff)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] == ' ')
			j++;
		i++;
	}
	if (!(aux = malloc(sizeof(char) * (i - j + 1))))
		return (0);
	i = 0;
	j = 0;
	while (buff[i])
	{
		if (buff[i] != ' ')
			aux[j++] = buff[i];
		i++;
	}
	aux[j] = '\0';
	return (aux);
}

void		ft_fill_map(t_struct *t, char *buff)
{
	int		size;
	char	*aux;
	char	*temp;

	aux = ft_without_spaces(buff);
	size = ft_strlen(aux);
	t->map_height++;
	if (!t->map_reader)
	{
		t->map_width = size;
		temp = ft_strdup(aux);
		t->map_reader = ft_strjoin(temp, "\n");
		free(temp);
	}
	else
	{
		if (t->map_width != size)
			ft_error("El mapa no es rectangular");
		temp = ft_strjoin(t->map_reader, aux);
		free(t->map_reader);
		t->map_reader = ft_strjoin(temp, "\n");
		free(temp);
	}
	free(aux);
}
