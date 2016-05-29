# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguillia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/30 12:22:42 by sguillia          #+#    #+#              #
#    Updated: 2016/05/29 22:52:48 by sguillia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = arkanoid

FLAGS = -Wall -Wextra -Werror -Wno-deprecated-declarations

GLFW = -lglfw3				\
	   -framework Cocoa		\
	   -framework OpenGL	\
	   -framework IOKit		\
	   -framework CoreVideo \
	   -framework Carbon	\
	   -framework GLUT

SRC = \
	  ball_motion.c				\
	  buf_is_black.c			\
	  change_level.c			\
	  check_malloc.c			\
	  collides.c				\
	  display.c					\
	  display_game.c			\
	  display_lose.c			\
	  display_menu.c			\
	  display_win.c				\
	  do_ball_motion.c			\
	  draw_ball.c				\
	  draw_bar.c				\
	  draw_brick.c				\
	  draw_header.c				\
	  draw_walls.c				\
	  fd_to_tbrick_list.c		\
	  frame_shouldwait.c		\
	  future_ball_collision.c	\
	  get_level.c				\
	  handle_bar_position.c		\
	  handle_collision.c		\
	  init_game.c				\
	  init_gl.c					\
	  key_callback.c			\
	  line_to_brick.c			\
	  main.c					\
	  process_game.c			\
	  reset_game.c				\
	  reverse_deltas.c			\
	  throw_error.c

OBJ = $(SRC:.c=.o)

#all : glfw $(NAME)
all : makelibft $(NAME)

makelibft:
	git submodule init
	git submodule update
	cd glfw && cmake . && make
	make -C libft

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
