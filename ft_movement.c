/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:06:35 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 18:12:47 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_mouse(int x, int y, t_struct *t)
{
	t->dir_x = sin((x * 720 / t->win_width) * M_PI / 180);
	t->dir_y = cos((x * 720 / t->win_width) * M_PI / 180);
	t->plane_x = 0.66 * t->dir_y;
	t->plane_y = -0.66 * t->dir_x;
	return (0);
}

static void	ft_rotate(t_struct *t)
{
	if (t->rotate_right == 1)
	{
		t->old_dir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(-t->rot_speed)
		- t->dir_y * sin(-t->rot_speed);
		t->dir_y = t->old_dir_x * sin(-t->rot_speed)
		+ t->dir_y * cos(-t->rot_speed);
		t->old_plane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(-t->rot_speed)
		- t->plane_y * sin(-t->rot_speed);
		t->plane_y = t->old_plane_x * sin(-t->rot_speed)
		+ t->plane_y * cos(-t->rot_speed);
	}
	if (t->rotate_left == 1)
	{
		t->old_dir_x = t->dir_x;
		t->dir_x = t->dir_x * cos(t->rot_speed) - t->dir_y * sin(t->rot_speed);
		t->dir_y = t->old_dir_x * sin(t->rot_speed)
		+ t->dir_y * cos(t->rot_speed);
		t->old_plane_x = t->plane_x;
		t->plane_x = t->plane_x * cos(t->rot_speed)
		- t->plane_y * sin(t->rot_speed);
		t->plane_y = t->old_plane_x * sin(t->rot_speed)
		+ t->plane_y * cos(t->rot_speed);
	}
}

static void	ft_move_2(t_struct *t)
{
	if (t->right == 1)
	{
		if (t->map[(int)(t->pos_x + t->dir_y * t->move_speed)]
		[(int)(t->pos_y)] == '0')
			t->pos_x += t->dir_y * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y - t->dir_x *
		t->move_speed)] == '0')
			t->pos_y -= t->dir_x * t->move_speed;
	}
	if (t->left == 1)
	{
		if (t->map[(int)(t->pos_x - t->dir_y * t->move_speed)]
		[(int)(t->pos_y)] == '0')
			t->pos_x -= t->dir_y * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y + t->dir_x *
		t->move_speed)] == '0')
			t->pos_y += t->dir_x * t->move_speed;
	}
}

static void	ft_move(t_struct *t)
{
	if (t->up == 1)
	{
		if (t->map[(int)(t->pos_x + t->dir_x * t->move_speed)]
		[(int)(t->pos_y)] == '0')
			t->pos_x += t->dir_x * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y + t->dir_y *
		t->move_speed)] == '0')
			t->pos_y += t->dir_y * t->move_speed;
	}
	if (t->down == 1)
	{
		if (t->map[(int)(t->pos_x - t->dir_x * t->move_speed)]
		[(int)(t->pos_y)] == '0')
			t->pos_x -= t->dir_x * t->move_speed;
		if (t->map[(int)(t->pos_x)][(int)(t->pos_y - t->dir_y *
		t->move_speed)] == '0')
			t->pos_y -= t->dir_y * t->move_speed;
	}
}

void		ft_movement(t_struct *t)
{
	ft_move(t);
	ft_move_2(t);
	ft_rotate(t);
	ft_rotate_up_down(t);
}
