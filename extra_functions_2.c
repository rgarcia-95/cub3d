/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:50:08 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/21 20:01:57 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*suc;

	i = 0;
	suc = (unsigned char *)s;
	while (i < n)
	{
		suc[i] = 0;
		i++;
	}
	s = suc;
}

int			init_sound(t_struct *t)
{
	if (!(t->sound = malloc(sizeof(t_sound))))
		return (-1);
	ft_bzero(t->sound, sizeof(t_sound));
	t->sound->last_start_song = clock();
	system("afplay -v 0.30 sounds/maintheme.mp3 &>/dev/null &");
	return (0);
}

int			count_lines(char *str)
{
	int	lines;

	lines = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			lines++;
		str++;
	}
	return (lines);
}

int			check_walls(t_struct *t)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = count_lines(t->map_reader) - 1;
	while (t->map[i])
	{
		k = 0;
		while (t->map[i][k])
		{
			if (t->map[0][k] == '0')
				return (0);
			if (t->map[i][k + 1] == '\0' && t->map[i][k] == '0')
				return (0);
			if (t->map[j][k] == '0')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
