/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:38:58 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:40:59 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_last_checker(t_struct *t)
{
	if (t->pos_player == 0)
		ft_error("No se ha identificado ninguna posición inicial!");
	if (check_walls(t) == 0)
		ft_error("El mapa no está rodeado por muros!");
}

static void	ft_check_player_eow(t_struct *t, char pos)
{
	if (pos == 'E')
	{
		t->dir_x = 0.0;
		t->dir_y = 1.0;
		t->plane_x = 0.66;
		t->plane_y = 0.0;
	}
	else
	{
		t->dir_x = 0.0;
		t->dir_y = -1.0;
		t->plane_x = -0.66;
		t->plane_y = 0.0;
	}
}

static void	ft_check_player(t_struct *t, char pos, int x, int y)
{
	t->map[x][y] = '0';
	if (t->pos_player == 0)
	{
		t->pos_player = 1;
		t->pos_x = (double)x + 0.5;
		t->pos_y = (double)y + 0.5;
		if (pos == 'N')
		{
			t->dir_x = -1.0;
			t->dir_y = 0.0;
			t->plane_x = 0.0;
			t->plane_y = 0.66;
		}
		else if (pos == 'S')
		{
			t->dir_x = 1.0;
			t->dir_y = 0.0;
			t->plane_x = 0.0;
			t->plane_y = -0.66;
		}
		else
			ft_check_player_eow(t, pos);
	}
	else
		ft_error("Mapa Inválido! Más de una posición");
}

void		ft_check_map(t_struct *t)
{
	while (t->map[t->map_x])
	{
		t->map_y = 0;
		while (t->map[t->map_x][t->map_y])
		{
			t->aux = t->map[t->map_x][t->map_y];
			if (t->aux == '0' || t->aux == '1' || t->aux == '2' || t->aux
			== 'N' || t->aux == 'S' || t->aux == 'E' || t->aux == 'W')
			{
				if (t->aux == '2')
					t->num_sprites++;
				else if (t->aux == 'N' || t->aux == 'S' || t->aux == 'E'
				|| t->aux == 'W')
					ft_check_player(t, t->aux, t->map_x, t->map_y);
				t->map_y++;
			}
			else
				ft_error("El mapa contiene carácteres inválidos!");
		}
		t->map_x++;
	}
	ft_last_checker(t);
}
