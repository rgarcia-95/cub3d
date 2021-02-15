/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:18:01 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 13:37:42 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_aux_reader_colors(t_struct *t, char *buff)
{
	int	temp;

	if (!buff)
		ft_error("No se ha especificado el color!");
	if (ft_atoi(buff) >= 256)
		ft_error("Formato RGB inválido!");
	t->sky_color = 0;
	temp = (ft_atoi(buff) * 256 * 256);
	buff += ft_count(ft_atoi(buff), 10);
	if (*buff == ',' && ft_isdigit(*(buff + 1)))
	{
		if (ft_atoi(++buff) >= 256)
			ft_error("Formato RGB inválido!");
		temp += (ft_atoi(buff) * 256);
		buff += ft_count(ft_atoi(buff), 10);
		if (*buff == ',' && ft_isdigit(*(buff + 1)))
		{
			if (ft_atoi(++buff) >= 256)
				ft_error("Formato RGB inválido!");
			temp += ft_atoi(buff);
			t->sky_color = temp;
		}
	}
	if (!t->sky_color)
		ft_error("Formato RGB inválido!");
}

static char	*ft_aux_reader_strings(t_struct *t, char *buff)
{
	char	*str;

	str = NULL;
	if (!buff)
		ft_error("No se ha especificado la textura!");
	while (*buff != '.')
		buff++;
	if (*buff == '.')
	{
		buff++;
		if (*buff == '/')
		{
			buff++;
			if (*buff == 't')
				if (!ft_strncmp("textures/", buff, 9))
					str = ft_strdup(buff);
		}
	}
	if (!str)
		ft_error("Textura incorrecta!");
	return (str);
}

static void	ft_aux_reader_res(t_struct *t, char *buff)
{
	if (!buff)
		ft_error("No se ha especificado la resolución!");
	t->win_width = (ft_atoi(buff) > 1920) ? 1920 : ft_atoi(buff);
	if (!t->win_width || t->win_width < 250)
		ft_error("La anchura de la pantalla es inválida!");
	buff += ft_count(t->win_width, 10);
	t->win_height = (ft_atoi(buff) > 1280) ? 1280 : ft_atoi(buff);
	if (!t->win_height || t->win_height < 250)
		ft_error("La altura de la pantalla es inválida!");
	if (t->win_width < t->win_height)
		ft_error("Dimensiones incorrectas!");
}

static void	ft_aux_reader_1(t_struct *t, char *buff)
{
	if (buff[0] != '\0')
	{
		if (buff[0] == 'R' && buff[1] == ' ')
			ft_aux_reader_res(t, buff + 2);
		else if (buff[0] == 'N' && buff[1] == 'O')
			t->no_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'S' && buff[1] == 'O')
			t->so_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'W' && buff[1] == 'E')
			t->we_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'E' && buff[1] == 'A')
			t->ea_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'S' && buff[1] == ' ')
			t->s_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'F' && buff[1] == ' ')
			t->f_texture = ft_aux_reader_strings(t, buff + 2);
		else if (buff[0] == 'C' && buff[1] == ' ')
			ft_aux_reader_colors(t, buff + 2);
		else if (buff[0] == '1')
			ft_fill_map(t, buff);
		else if (buff[0] == '0')
			ft_error("El mapa no está rodeado por muros!");
		else
			ft_error("Archivo .cub inválido!");
	}
}

void		ft_map_reader(t_struct *t, char *argv)
{
	int		fd;
	int		ret;
	int		line;
	char	*buff;

	ret = 0;
	line = 0;
	buff = NULL;
	fd = open(argv, O_RDWR);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		ft_aux_reader_1(t, buff);
		free(buff);
		buff = NULL;
	}
	ft_aux_reader_1(t, buff);
	if (buff)
		free(buff);
	if (ret == -1)
		ft_error("No se pudo leer el archivo correctamente!");
	t->map = ft_split(t->map_reader, '\n');
	ft_check_map(t);
}
