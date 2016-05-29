/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_deltas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:26:15 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 22:06:59 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int	collides_bar(t_game *game)
{
	t_ball	ball;
	t_bar	bar;

	ball = game->ball;
	bar = game->bar;
	if ((ball.x >= bar.x && ball.x <= bar.x + BAR_WIDTH)
			&& (ball.y + BALL_SIZE >= WIN_HEIGHT - BAR_MARGIN - 15))
	{
		if (ball.x >= bar.x
				&& ball.x <= (bar.x + bar.x + BAR_WIDTH) / (double)2)
			game->ball.dx = -1;
		else
			game->ball.dx = 1;
		game->ball.dy = -1;
		do_ball_motion(game);
		return (1);
	}
	else
		return (0);
}

void		reverse_deltas(t_game *game, int type)
{
	if (!collides_bar(game))
	{
		if (type == 1)
			game->ball.dy *= -1;
		else if (type == 2)
			game->ball.dy *= -1;
		else if (type == 3)
			game->ball.dx *= -1;
		else if (type == 4)
			game->ball.dx *= -1;
	}
}
