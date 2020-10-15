/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:51:37 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:52:04 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw(t_struct *t, int x)
{
	int y;
	int	z;

	y = 0;
	if ((t->side == 0 && t->ray_dir_x > 0)
	|| (t->side == 1 && t->ray_dir_y < 0))
		t->tex_x = t->text_width - t->tex_x - 1;
	while (y < t->draw_start)
	{
		ft_memcpy(t->img_data + 4 * t->win_width * y + x * 4,
		&t->sky_color, sizeof(int));
		y++;
	}
	while (y < t->draw_end)
	{
		z = (int)((((y * 256 - t->win_height * 128 * t->cam_height +
		t->line_height * 128) * 64) / t->line_height) / 256);
		t->tex_y = abs(z);
		ft_memcpy(t->img_data + 4 * t->win_width * y + x * 4,
		&t->text[t->tex_num].s_img_data[t->tex_y % t->text_height
		* t->text[t->tex_num].s_size_line + t->tex_x % t->text_width
		* t->text[t->tex_num].s_bpp / 8], sizeof(int));
		y++;
	}
}

static void	ft_check_colors(t_struct *t)
{
	if (t->side == 0)
		t->perp_wall_dist = (t->map_x - t->pos_x +
		(1 - t->step_x) / 2) / t->ray_dir_x;
	else
		t->perp_wall_dist = (t->map_y - t->pos_y +
		(1 - t->step_y) / 2) / t->ray_dir_y;
	t->line_height = (int)(t->win_height / t->perp_wall_dist);
	t->draw_start = -t->line_height / 2 + ((t->win_height / 2) *
	t->cam_height);
	if (t->draw_start < 0)
		t->draw_start = 0;
	t->draw_end = t->line_height / 2 + ((t->win_height / 2) *
	t->cam_height);
	if (t->draw_end >= t->win_height)
		t->draw_end = t->win_height - 1;
	ft_check_textures(t);
	t->tex_num = (t->map[t->map_x][t->map_y] - 1) - '0';
	t->tex_num += t->text_side;
	if (t->side == 0)
		t->wall_x = t->pos_y + t->perp_wall_dist * t->ray_dir_y;
	else
		t->wall_x = t->pos_x + t->perp_wall_dist * t->ray_dir_x;
	t->wall_x -= floor(t->wall_x);
	t->tex_x = (int)(t->wall_x * (double)(t->text_width));
}

static void	ft_check_hit(t_struct *t)
{
	while (t->hit == 0)
	{
		if (t->side_dist_x < t->side_dist_y)
		{
			t->side_dist_x += t->delta_dist_x;
			t->map_x += t->step_x;
			t->side = 0;
		}
		else
		{
			t->side_dist_y += t->delta_dist_y;
			t->map_y += t->step_y;
			t->side = 1;
		}
		if (t->map[t->map_x][t->map_y] == '1')
			t->hit = 1;
	}
}

static void	ft_check_raydir(t_struct *t)
{
	t->map_x = (int)t->pos_x;
	t->map_y = (int)t->pos_y;
	t->delta_dist_x = fabs(1 / t->ray_dir_x);
	t->delta_dist_y = fabs(1 / t->ray_dir_y);
	t->hit = 0;
	if (t->ray_dir_x < 0)
	{
		t->step_x = -1;
		t->side_dist_x = (t->pos_x - t->map_x) * t->delta_dist_x;
	}
	else
	{
		t->step_x = 1;
		t->side_dist_x = (t->map_x + 1.0 - t->pos_x) * t->delta_dist_x;
	}
	if (t->ray_dir_y < 0)
	{
		t->step_y = -1;
		t->side_dist_y = (t->pos_y - t->map_y) * t->delta_dist_y;
	}
	else
	{
		t->step_y = 1;
		t->side_dist_y = (t->map_y + 1.0 - t->pos_y) * t->delta_dist_y;
	}
}

int			ft_loop_raycast(t_struct *t)
{
	int x;

	x = -1;
	ft_movement(t);
	t->img_ptr = mlx_new_image(t->mlx_ptr, t->win_width, t->win_height);
	t->img_data = mlx_get_data_addr(t->img_ptr, &t->bpp,
	&t->size_line, &t->end);
	while (++x < t->win_width)
	{
		t->camera_x = 2 * x / (double)(t->win_width) - 1;
		t->ray_dir_x = t->dir_x + t->plane_x * t->camera_x;
		t->ray_dir_y = t->dir_y + t->plane_y * t->camera_x;
		ft_check_raydir(t);
		ft_check_hit(t);
		ft_check_colors(t);
		ft_loop_floor(t, x);
		ft_draw(t, x);
		t->zbuffer[x] = t->perp_wall_dist;
	}
	ft_sprites(t);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr, t->img_ptr, 0, 0);
	ft_init_minimap(t);
	return (0);
}
