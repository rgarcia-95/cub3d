/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:54:42 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:55:00 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_square(t_struct *t, int y, int x, int color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	j = x;
	i = y;
	width = MINIMAP_SIZE;
	height = MINIMAP_SIZE;
	while (j < (width + x))
	{
		i = y;
		while (i < (height + y))
		{
			mlx_pixel_put(t->mlx_ptr, t->win_ptr, i, j, color);
			i++;
		}
		j++;
	}
}

static int	get_color_minimap(t_struct *t, int i, int j)
{
	int	color;

	if (t->map[i][j] == '1')
		color = COLOR_MAP_WALL;
	else if (t->map[i][j] == '2')
		color = COLOR_MAP_SPRITE;
	else
		color = COLOR_MAP_FLOOR;
	return (color);
}

void		ft_init_minimap(t_struct *t)
{
	int	i;
	int	j;
	int	color;
	int	offset_x;

	i = 0;
	offset_x = t->win_width / 2 - (t->map_width * MINIMAP_SIZE) / 2;
	while (i < t->map_height)
	{
		j = 0;
		while (t->map[i][j] != '\0')
		{
			color = get_color_minimap(t, i, j);
			draw_square(t, j * MINIMAP_SIZE, offset_x +
			i * MINIMAP_SIZE, color);
			j++;
		}
		i++;
	}
	draw_square(t, (t->pos_y - 0.5) * MINIMAP_SIZE, offset_x +
	(t->pos_x - 0.5) * MINIMAP_SIZE, COLOR_MAP_PLAYER);
}
