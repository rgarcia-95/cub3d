/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:50:56 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:51:23 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check_textures(t_struct *t)
{
	if (t->side == 0 && t->ray_dir_x < 0)
		t->text_side = 0;
	else if (t->side == 0 && t->ray_dir_x > 0)
		t->text_side = 1;
	else if (t->side == 1 && t->ray_dir_y < 0)
		t->text_side = 2;
	else if (t->side == 1 && t->ray_dir_y > 0)
		t->text_side = 3;
}

static void	ft_load_textures_2(t_struct *t)
{
	if (!(t->text[4].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->s_texture, &t->text_width, &t->text_height)))
		ft_error("La textura del sprite es inválida!");
	t->text[4].s_img_data = mlx_get_data_addr(t->text[4].s_img_ptr,
	&t->text[4].s_bpp, &t->text[4].s_size_line, &t->text[4].s_end);
	if (!(t->text[5].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->f_texture, &t->text_width, &t->text_height)))
		ft_error("La textura del suelo es inválida!");
	t->text[5].s_img_data = mlx_get_data_addr(t->text[5].s_img_ptr,
	&t->text[5].s_bpp, &t->text[5].s_size_line, &t->text[5].s_end);
}

void		ft_load_textures(t_struct *t)
{
	if (!(t->text[0].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->no_texture, &t->text_width, &t->text_height)))
		ft_error("La textura norte es inválida!");
	t->text[0].s_img_data = mlx_get_data_addr(t->text[0].s_img_ptr,
	&t->text[0].s_bpp, &t->text[0].s_size_line, &t->text[0].s_end);
	if (!(t->text[1].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->so_texture, &t->text_width, &t->text_height)))
		ft_error("La textura sur es inválida!");
	t->text[1].s_img_data = mlx_get_data_addr(t->text[1].s_img_ptr,
	&t->text[1].s_bpp, &t->text[1].s_size_line, &t->text[1].s_end);
	if (!(t->text[2].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->we_texture, &t->text_width, &t->text_height)))
		ft_error("La textura oeste es inválida!");
	t->text[2].s_img_data = mlx_get_data_addr(t->text[2].s_img_ptr,
	&t->text[2].s_bpp, &t->text[2].s_size_line, &t->text[2].s_end);
	if (!(t->text[3].s_img_ptr = mlx_xpm_file_to_image(t->mlx_ptr,
	t->ea_texture, &t->text_width, &t->text_height)))
		ft_error("La textura este es inválida!");
	t->text[3].s_img_data = mlx_get_data_addr(t->text[3].s_img_ptr,
	&t->text[3].s_bpp, &t->text[3].s_size_line, &t->text[3].s_end);
	ft_load_textures_2(t);
}
