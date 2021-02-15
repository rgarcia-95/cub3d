/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:08:14 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 13:55:34 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_principal_save(t_struct *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->win_width, t->win_height, "");
	ft_load_textures(t);
	ft_loop_raycast(t);
	ft_screenshot(t);
	free(t);
	t = NULL;
	return (0);
}

static int	ft_principal(t_struct *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, t->win_width, t->win_height, "");
	init_sound(t);
	ft_load_textures(t);
	mlx_hook(t->win_ptr, 2, 0, ft_key_press, t);
	mlx_hook(t->win_ptr, 3, 0, ft_key_release, t);
	mlx_hook(t->win_ptr, 6, 0, ft_mouse, t);
	mlx_hook(t->win_ptr, 17, 0, ft_exit, NULL);
	mlx_loop_hook(t->mlx_ptr, ft_loop_raycast, t);
	mlx_loop(t->mlx_ptr);
	free(t);
	t = NULL;
	return (0);
}

static void	ft_check_arg(char *argv)
{
	while (*argv != '.')
		argv++;
	if (ft_strncmp(".cub", argv, ft_strlen(argv)) != 0)
		ft_error("El mapa no es formato .cub!");
}

static void	ft_init_struct(t_struct *t)
{
	t->map_x = 0;
	t->map_y = 0;
	t->map_width = 0;
	t->map_height = 0;
	t->pos_player = 0;
	t->text_width = 64;
	t->text_height = 64;
	t->rot_speed = 0.10;
	t->move_speed = 0.10;
	t->map_reader = NULL;
	t->cam_height = 1.0;
	t->num_sprites = 0;
}

int			main(int argc, char **argv)
{
	t_struct	*t;

	if (!(t = malloc(sizeof(t_struct))))
		return (-1);
	ft_init_struct(t);
	if (argc > 1)
	{
		ft_check_arg(argv[1]);
		ft_map_reader(t, argv[1]);
		ft_mallocs(t);
		ft_check_pos_sprites(t);
		if (argc == 2)
			ft_principal(t);
		else if (argc == 3 && (!ft_strncmp("--save", argv[2],
		ft_strlen(argv[2]))))
			ft_principal_save(t);
		else
			ft_error("Argumentos inválidos!");
	}
	else
		ft_error("No hay ningún argumento!");
	return (0);
}
