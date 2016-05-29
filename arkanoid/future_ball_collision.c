/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   future_ball_collision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:14:49 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 16:33:46 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int	is_black_up(t_game *game, char *buf)
{
	glReadPixels(game->ball.x,
			WIN_HEIGHT - game->ball.y, BALL_SIZE, 1,
			GL_RED | GL_GREEN | GL_BLUE, GL_UNSIGNED_BYTE, buf);
	if (buf_is_black(buf, BALL_SIZE * 3))
		return (1);
	return (0);
}

static int	is_black_down(t_game *game, char *buf)
{
	glReadPixels(game->ball.x,
			WIN_HEIGHT - 1 - game->ball.y - BALL_SIZE, BALL_SIZE, 1,
			GL_RED | GL_GREEN | GL_BLUE, GL_UNSIGNED_BYTE, buf);
	if (buf_is_black(buf, BALL_SIZE * 3))
		return (1);
	return (0);
}

static int	is_black_left(t_game *game, char *buf)
{
	glReadPixels(game->ball.x - 1,
			WIN_HEIGHT - 1 - game->ball.y - BALL_SIZE + 1, 1, BALL_SIZE,
			GL_RED | GL_GREEN | GL_BLUE, GL_UNSIGNED_BYTE, buf);
	if (buf_is_black(buf, BALL_SIZE * 3))
		return (1);
	return (0);
}

static int	is_black_right(t_game *game, char *buf)
{
	glReadPixels(game->ball.x + BALL_SIZE,
			WIN_HEIGHT - 1 - game->ball.y - BALL_SIZE + 1, 1, BALL_SIZE,
			GL_RED | GL_GREEN | GL_BLUE, GL_UNSIGNED_BYTE, buf);
	if (buf_is_black(buf, BALL_SIZE * 3))
		return (1);
	return (0);
}

int			future_ball_collision(t_game *game)
{
	char	buf[BALL_SIZE * 3];

	if (ball_motion(game, "UP"))
		if (!is_black_up(game, buf))
			return (1);
	if (ball_motion(game, "DOWN"))
		if (!is_black_down(game, buf))
			return (2);
	if (ball_motion(game, "LEFT"))
		if (!is_black_left(game, buf))
			return (3);
	if (ball_motion(game, "RIGHT"))
		if (!is_black_right(game, buf))
			return (4);
	return (0);
}
