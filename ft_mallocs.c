/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:13:35 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 18:16:38 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mallocs(t_struct *t)
{
	if (!(t->zbuffer = malloc(sizeof(double) * t->win_width + 1)))
		return (-1);
	if (!(t->sprites = malloc(sizeof(t_sprites) * t->num_sprites)))
		return (-1);
	if (!(t->sprite_order = malloc(sizeof(int) * t->num_sprites)))
		return (-1);
	if (!(t->sprite_distance = malloc(sizeof(double) * t->num_sprites)))
		return (-1);
	return (0);
}
