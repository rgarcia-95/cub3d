/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:53:53 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:54:12 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_sprite(t_struct *t, int stripe, int y)
{
	int	z;

	z = (int)(((((y * 256 - (t->win_height * 128 * t->cam_height)
	+ t->sprite_height * 128) * t->text_height) /
	t->sprite_height) / 256));
	t->tex_sprite_y = abs(z);
	if ((t->text[4].s_img_data[t->tex_sprite_y % 64 *
	t->text[4].s_size_line + t->tex_sprite_x % 64 *
	t->text[4].s_bpp / 8] != 0))
		ft_memcpy(t->img_data + 4 * t->win_width * y + stripe * 4,
		&t->text[4].s_img_data[t->tex_sprite_y % 64 *
		t->text[4].s_size_line + t->tex_sprite_x % 64 *
		t->text[4].s_bpp / 8], sizeof(int));
}

static void	aux_loop_sprites(t_struct *t)
{
	int	stripe;
	int	y;

	stripe = t->draw_start_x - 1;
	while (++stripe < t->draw_end_x)
	{
		t->tex_sprite_x = (int)(256 * (stripe -
		(-t->sprite_width / 2 + t->sprite_screen_x))
		* t->text_width / t->sprite_width) / 256;
		y = t->draw_start_y - 1;
		if (t->transform_y > 0 && stripe > 0 && stripe
		< t->win_width && t->transform_y < t->zbuffer[stripe])
			while (++y < t->draw_end_y)
				draw_sprite(t, stripe, y);
	}
}

static void	aux_sprites(t_struct *t)
{
	t->draw_end_y = t->sprite_height / 2 +
	((t->win_height / 2) * t->cam_height);
	if (t->draw_end_y >= t->win_height)
		t->draw_end_y = t->win_height - 1;
	t->sprite_width = abs((int)(t->win_height /
	t->transform_y));
	t->draw_start_x = (-t->sprite_width / 2)
	+ t->sprite_screen_x;
	if (t->draw_start_x < 0)
		t->draw_start_x = 0;
	t->draw_end_x = t->sprite_width / 2 +
	t->sprite_screen_x;
	if (t->draw_end_x >= t->win_width)
		t->draw_end_x = t->win_width - 1;
	aux_loop_sprites(t);
}

void		ft_sprites(t_struct *t)
{
	int	i;

	i = -1;
	ft_check_sprites(t);
	while (++i < t->num_sprites)
	{
		t->sprite_x = t->sprites[t->sprite_order[i]].x - t->pos_x;
		t->sprite_y = t->sprites[t->sprite_order[i]].y - t->pos_y;
		t->inv_det = 1.0 / (t->plane_x * t->dir_y - t->dir_x *
		t->plane_y);
		t->transform_x = t->inv_det * (t->dir_y *
		t->sprite_x - t->dir_x * t->sprite_y);
		t->transform_y = t->inv_det * (-t->plane_y *
		t->sprite_x + t->plane_x * t->sprite_y);
		t->sprite_screen_x = (int)(t->win_width / 2) * (1 +
		t->transform_x / t->transform_y);
		t->sprite_height = abs((int)(t->win_height /
		t->transform_y));
		t->draw_start_y = (-t->sprite_height / 2) +
		((t->win_height / 2) * t->cam_height);
		if (t->draw_start_y < 0)
			t->draw_start_y = 0;
		aux_sprites(t);
	}
}
