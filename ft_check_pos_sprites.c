/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pos_sprites.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:48:15 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:48:43 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_pos_sprites(t_struct *t)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (t->map[i])
	{
		j = 0;
		while (t->map[i][j])
		{
			t->aux = t->map[i][j];
			if (t->aux == '2')
			{
				t->sprites[z].x = (double)i + 0.5;
				t->sprites[z].y = (double)j + 0.5;
				z++;
			}
			j++;
		}
		i++;
	}
}
