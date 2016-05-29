/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arkanoid.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:14:58 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 22:50:26 by sguillia         ###   ########.fr       */
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

void			*check_malloc(void *content);
void			display(t_game *game);
void			draw_bar(void);
void			draw_brick(t_list *bricks);
void			draw_grid(void);
void			draw_temp_brick(t_game *game);
void			draw_walls(void);
void			dump_brick(t_brick *brick);
void			dump_level(t_list *lvl);
void			getmousepos(GLFWwindow *window, int *mx, int *my);
void			init_game(t_game *game);
void			init_gl(t_game *game_info);
void			key_callback(GLFWwindow *w, int k, int s, int action, int mods);
int				main(void);
void			modcolor(int r, int g, int b);
void			mouse_callback(GLFWwindow *window, int button, int action,
					int mods);
void			mousemath(int *x, int *y);
void			outputme(int x, int y);
void			setcolor(void);
int				throw_error(char *cmd, char *subcmd);

#endif
