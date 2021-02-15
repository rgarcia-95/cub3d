/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 17:18:18 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 13:13:36 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42

# define MINIMAP_SIZE 10
# define COLOR_MAP_WALL 0x000000
# define COLOR_MAP_PLAYER 0xff0000
# define COLOR_MAP_FLOOR 0xffffff
# define COLOR_MAP_SPRITE 0x00ff00

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct	s_sound
{
	clock_t		last_start_song;
}				t_sound;

typedef struct	s_sprites
{
	double		x;
	double		y;
}				t_sprites;

typedef struct	s_textures
{
	void		*s_img_ptr;
	char		*s_img_data;
	int			s_bpp;
	int			s_size_line;
	int			s_end;
}				t_textures;

typedef struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	int			pos_player;
	char		**map;
	char		*map_reader;
	int			map_width;
	int			map_height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			sky_color;
	double		old_dir_x;
	double		old_plane_x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	int			up;
	int			down;
	int			left;
	int			right;
	int			rotate_up;
	int			rotate_down;
	int			rotate_left;
	int			rotate_right;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			end;
	int			text_width;
	int			text_height;
	t_textures	text[6];
	int			text_side;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*f_texture;
	char		*s_texture;
	char		aux;
	t_sprites	*sprites;
	double		*zbuffer;
	double		floor_x_wall;
	double		floor_y_wall;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
	t_sound		*sound;
	double		cam_height;
	int			num_sprites;
	int			*sprite_order;
	double		*sprite_distance;
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_sprite_x;
	int			tex_sprite_y;
}				t_struct;

void			ft_map_reader(t_struct *t, char *argv);
void			ft_fill_map(t_struct *t, char *buff);
void			ft_check_map(t_struct *t);
int				ft_mallocs(t_struct *t);
int				get_next_line(const int fd, char **line);
int				ft_loop_raycast(t_struct *t);
void			ft_loop_floor(t_struct *t, int x);
void			ft_load_textures(t_struct *t);
void			ft_check_textures(t_struct *t);
void			ft_sprites(t_struct *t);
void			ft_check_sprites(t_struct *t);
void			ft_check_pos_sprites(t_struct *t);
int				count_lines(char *str);
int				check_walls(t_struct *t);
void			ft_movement(t_struct *t);
void			ft_rotate_up_down(t_struct *t);
int				ft_mouse(int x, int y, t_struct *t);
int				ft_exit(void);
void			ft_error(char *s);
int				ft_key_press(int key, t_struct *t);
int				ft_key_release(int key, t_struct *t);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char *str, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_count(long long n, int base_len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				init_sound(t_struct *t);
int				ft_screenshot(t_struct *t);
void			ft_init_minimap(t_struct *t);

#endif
