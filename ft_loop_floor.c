/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:57:44 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 20:00:46 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_aux_loop_floor(t_struct *t)
{
	if (t->side == 0 && t->ray_dir_x > 0)
	{
		t->floor_x_wall = t->map_x;
		t->floor_y_wall = t->map_y + t->wall_x;
	}
	else if (t->side == 0 && t->ray_dir_x < 0)
	{
		t->floor_x_wall = t->map_x + 1.0;
		t->floor_y_wall = t->map_y + t->wall_x;
	}
	else if (t->side == 1 && t->ray_dir_y > 0)
	{
		t->floor_x_wall = t->map_x + t->wall_x;
		t->floor_y_wall = t->map_y;
	}
	else
	{
		t->floor_x_wall = t->map_x + t->wall_x;
		t->floor_y_wall = t->map_y + 1.0;
	}
	t->dist_wall = t->perp_wall_dist;
	t->dist_player = 0.0;
}

void		ft_loop_floor(t_struct *t, int x)
{
	int	y;

	ft_aux_loop_floor(t);
	if (t->draw_end < 0)
		t->draw_end = t->win_height;
	y = t->draw_end;
	while (++y < t->win_height)
	{
		t->current_dist = t->win_height / (2.0 * y - t->win_height *
		t->cam_height);
		t->weight = (t->current_dist - t->dist_player) / (t->dist_wall -
		t->dist_player);
		t->current_floor_x = t->weight * t->floor_x_wall + (1.0 - t->weight)
		* t->pos_x;
		t->current_floor_y = t->weight * t->floor_y_wall + (1.0 - t->weight)
		* t->pos_y;
		t->floor_tex_x = (int)(t->current_floor_x * t->text_width)
		% t->text_width;
		t->floor_tex_y = (int)(t->current_floor_y * t->text_height)
		% t->text_height;
		ft_memcpy(t->img_data + 4 * t->win_width * y + x * 4,
		&t->text[5].s_img_data[t->floor_tex_y % t->text_height
		* t->text[5].s_size_line + t->floor_tex_x % t->text_width
		* t->text[5].s_bpp / 8], sizeof(int));
	}
}
