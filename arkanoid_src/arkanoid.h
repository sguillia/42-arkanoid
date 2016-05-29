/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:14:58 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 23:37:38 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARKANOID_H
# define ARKANOID_H

# include <GLFW/glfw3.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# define BRICK_STD		1
# define BRICK_NONBREAK	2

# define FRAMERATE			60
# define WIN_WIDTH			1600
# define WIN_HEIGHT			900
# define BRICK_WIDTH		60
# define BRICK_HEIGHT		30
# define INIT_LIFE			3
# define BAR_WIDTH			130
# define BAR_MARGIN			50
# define BALL_SIZE			10
# define MENU_MARGIN		150
# define MENU_ITEM_MARGIN	150
# define MENU				0
# define GAME				1
# define WIN				2
# define LOSE				3

# define LEVELS_PREFIX	"levels/lvl"

typedef struct	s_brick
{
	int		type;
	int		solidity;
	int		x;
	int		y;
	float	red;
	float	green;
	float	blue;
}				t_brick;

typedef struct	s_bar
{
	double		x;
	int			size;
	int			sticky_ball;
}				t_bar;

typedef struct	s_ball
{
	int			x;
	int			y;
	int			dx;
	int			dy;
}				t_ball;

typedef struct	s_game
{
	GLFWwindow	*window;
	int			display;
	int			lvl;
	t_list		*bricks;
	t_bar		bar;
	t_ball		ball;
	int			score;
	int			life;
	int			playing;
}				t_game;

int				ball_motion(t_game *game, char *str);
int				buf_is_black(char *buf, int size);
void			change_level(t_game *game);
void			*check_malloc(void *content);
int				collides(t_game *game, int type, t_brick *brick);
void			display(t_game *game);
void			display_game(t_game *game);
void			display_lose(t_game *game);
void			display_menu(t_game *game);
void			display_win(t_game *game);
void			do_ball_motion(t_game *game);
void			draw_ball(t_game *game);
void			draw_bar(t_game *game);
void			draw_brick(t_list *bricks);
void			draw_header(t_game *game);
void			draw_walls(void);
t_list			*fd_to_tbrick_list(int fd);
int				framerate_shouldwait(void);
int				future_ball_collision(t_game *game);
t_list			*get_level(int lvl);
void			handle_bar_position(t_game *game);
void			handle_collision(t_game *game, int type);
void			init_game(t_game *game);
void			init_gl(t_game *game_info, int ac, char **av);
void			key_callback(GLFWwindow *w, int k, int s, int action, int mods);
t_brick			*line_to_brick(char *line);
int				main(int ac, char **av);
void			process_game(t_game *game);
void			reset_game(t_game *game);
void			reverse_deltas(t_game *game, int type);
int				throw_error(char *cmd, char *subcmd);

#endif
