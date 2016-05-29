# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguillia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 12:22:42 by sguillia          #+#    #+#              #
#    Updated: 2016/01/31 23:00:03 by mdeken           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid_generator

FLAGS = -Wall -Wextra -Werror -Wno-deprecated-declarations
#FLAGS =

GLFW = -lglfw3				\
	   -framework Cocoa		\
	   -framework OpenGL	\
	   -framework IOKit		\
	   -framework CoreVideo \
	   -framework Carbon	\
	   -framework GLUT

SRC = check_malloc.c	\
	  display.c			\
  	  draw_bar.c		\
	  draw_brick.c		\
	  draw_grid.c		\
	  draw_temp_brick.c	\
	  draw_walls.c		\
	  dump_level.c		\
	  getmousepos.c		\
	  init_game.c		\
	  init_gl.c			\
	  key_callback.c	\
	  main.c			\
	  modcolor.c		\
	  mouse_callback.c	\
	  mousemath.c		\
	  outputme.c		\
	  setcolor.c		\
	  throw_error.c

#SRC = \
	  check_malloc.c		\
	  main.c				\
	  throw_error.c

OBJ = $(SRC:.c=.o)

#all : glfw $(NAME)
all : makelibft $(NAME)

makelibft:
	make -C libft

glfw :
	make -C glfw/

$(NAME) : $(OBJ)
	clang $(FLAGS) -o $(NAME) $^ $(GLFW) -L glfw/src -Ilibft -Llibft -lft
	@#clang $(FLAGS) -o $(NAME) $^ -Ilibft -Llibft -lft

%.o : %.c arkanoid.h
	clang $(FLAGS) -o $@ -c $< -I glfw/include/ -Ilibft
	@#clang $(FLAGS) -o $@ -c $< -Ilibft

clean :
	make -C libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

cleanp:
	rm -rf $(OBJ)

fcleanp: cleanp
	rm -rf $(NAME)

rep: fcleanp all

re: fclean all

.PHONY: glfw
