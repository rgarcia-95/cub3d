/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:50:06 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:50:28 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_sort_sprites(t_struct *t)
{
	int		i;
	int		j;
	int		aux_order;
	double	aux_dist;

	i = 0;
	while (i < (t->num_sprites - 1))
	{
		j = 0;
		while (j < (t->num_sprites - 1))
		{
			if (t->sprite_distance[j] < t->sprite_distance[j + 1])
			{
				aux_dist = t->sprite_distance[j];
				t->sprite_distance[j] = t->sprite_distance[j + 1];
				t->sprite_distance[j + 1] = aux_dist;
				aux_order = t->sprite_order[j];
				t->sprite_order[j] = t->sprite_order[j + 1];
				t->sprite_order[j + 1] = aux_order;
			}
			j++;
		}
		i++;
	}
}

void		ft_check_sprites(t_struct *t)
{
	int	i;

	i = 0;
	while (i < t->num_sprites)
	{
		t->sprite_order[i] = i;
		t->sprite_distance[i] = ((t->pos_x - t->sprites[i].x) *
		(t->pos_x - t->sprites[i].x) + (t->pos_y - t->sprites[i].y)
		* (t->pos_y - t->sprites[i].y));
		i++;
	}
	ft_sort_sprites(t);
}
