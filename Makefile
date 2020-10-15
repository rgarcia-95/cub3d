# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 16:27:54 by rgarcia-          #+#    #+#              #
#    Updated: 2020/09/21 16:51:10 by rgarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Cub3D

SRCS	=	main.c					\
			ft_map_reader.c			\
			ft_fill_map.c			\
			check_map.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_loop_raycast.c		\
			ft_loop_floor.c			\
			ft_load_textures.c		\
			ft_movement.c			\
			ft_mallocs.c			\
			ft_split.c				\
			actions.c				\
			ft_screenshot.c			\
			ft_sprites.c			\
			ft_check_sprites.c		\
			ft_check_pos_sprites.c	\
			ft_init_minimap.c		\
			ft_rotate_up_down.c		\
			extra_functions_1.c		\
			extra_functions_2.c		\

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

LIBS	=	-lmlx -framework OpenGL -framework AppKit

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean	:
		@/bin/rm -f $(OBJS)

fclean	:	clean
		@/bin/rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re