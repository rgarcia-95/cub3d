/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:38:17 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 20:03:03 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(void)
{
	system("killall afplay");
	exit(1);
	return (0);
}

void	ft_error(char *s)
{
	write(1, "Error\n", 6);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	ft_exit();
}

int		ft_key_release(int key, t_struct *t)
{
	if (key == W)
		t->up = 0;
	if (key == S)
		t->down = 0;
	if (key == D)
		t->right = 0;
	if (key == A)
		t->left = 0;
	if (key == UP && t->rotate_up == 1)
		t->rotate_up = 0;
	if (key == DOWN && t->rotate_down == 1)
		t->rotate_down = 0;
	if (key == RIGHT)
		t->rotate_right = 0;
	if (key == LEFT)
		t->rotate_left = 0;
	return (0);
}

int		ft_key_press(int key, t_struct *t)
{
	if (key == W)
		t->up = 1;
	if (key == S)
		t->down = 1;
	if (key == D)
		t->right = 1;
	if (key == A)
		t->left = 1;
	if (key == UP && t->rotate_up == 0)
		t->rotate_up = 1;
	if (key == DOWN && t->rotate_down == 0)
		t->rotate_down = 1;
	if (key == RIGHT)
		t->rotate_right = 1;
	if (key == LEFT)
		t->rotate_left = 1;
	if (key == ESC)
		ft_exit();
	return (0);
}
