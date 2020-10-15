/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:59:11 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:59:46 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn_up(t_struct *t)
{
	if (t->cam_height + t->rot_speed < 1.5)
		t->cam_height += t->rot_speed;
}

static void	turn_down(t_struct *t)
{
	if (t->cam_height - t->rot_speed > 0.5)
		t->cam_height -= t->rot_speed;
}

void		ft_rotate_up_down(t_struct *t)
{
	if (t->rotate_up == 1)
		turn_up(t);
	if (t->rotate_down == 1)
		turn_down(t);
}
