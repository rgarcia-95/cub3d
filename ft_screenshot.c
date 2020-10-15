/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:53:12 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/22 19:53:35 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_int_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	write_bmp_header(int fd, int filesize, t_struct *t)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
	{
		bmpfileheader[i] = (unsigned char)(0);
		i++;
	}
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_char(bmpfileheader + 18, t->win_width);
	set_int_char(bmpfileheader + 22, t->win_height);
	bmpfileheader[27] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	get_color(t_struct *t, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int *)(t->img_data + (4 * (int)t->win_width *
	((int)t->win_height - y - 1)) + (x * 4));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int	write_bmp_data(int file, t_struct *t, int pad)
{
	int					i;
	int					j;
	int					color;
	const unsigned char	zero[3] = {0, 0, 0};

	i = 0;
	while (i < (int)t->win_height)
	{
		j = 0;
		while (j < (int)t->win_width)
		{
			color = get_color(t, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_screenshot(t_struct *t)
{
	int	pad;
	int	file;
	int	filesize;

	pad = (4 - ((int)t->win_width * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)t->win_width + pad) * t->win_height);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
	| O_TRUNC | O_APPEND, 777)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, t))
		return (0);
	if (!write_bmp_data(file, t, pad))
		return (0);
	close(file);
	return (1);
}
