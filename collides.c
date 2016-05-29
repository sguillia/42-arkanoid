/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collides.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:25:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 17:25:09 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int	test1(t_brick *brick, t_ball ball)
{
	if (((ball.x > brick->x && ball.x < brick->x + BRICK_WIDTH)
				|| (ball.x + BALL_SIZE > brick->x
					&& ball.x + BALL_SIZE < brick->x + BRICK_WIDTH))
			&& ball.y >= brick->y && ball.y <= brick->y + BRICK_HEIGHT)
	{
		return (1);
	}
	return (0);
}

static int	test2(t_brick *brick, t_ball ball)
{
	if (((ball.x > brick->x && ball.x < brick->x + BRICK_WIDTH)
				|| (ball.x + BALL_SIZE > brick->x
					&& ball.x + BALL_SIZE < brick->x + BRICK_WIDTH))
			&& ball.y + BALL_SIZE >= brick->y
			&& ball.y + BALL_SIZE <= brick->y + BRICK_HEIGHT)
	{
		return (1);
	}
	return (0);
}

static int	test3(t_brick *brick, t_ball ball)
{
	if (ball.x + ball.dx > brick->x && ball.x + ball.dx < brick->x + BRICK_WIDTH
			&& ((ball.y + BALL_SIZE > brick->y
					&& ball.y + BALL_SIZE < brick->y + BRICK_HEIGHT)
				|| (ball.y > brick->y && ball.y < brick->y + BRICK_HEIGHT)))
	{
		return (1);
	}
	return (0);
}

static int	test4(t_brick *brick, t_ball ball)
{
	if (((ball.y > brick->y && ball.y < brick->y + BRICK_HEIGHT)
				|| (ball.y + BALL_SIZE > brick->y
					&& ball.y + BALL_SIZE < brick->y + BRICK_HEIGHT))
			&& ball.x + BALL_SIZE + ball.dx > brick->x
			&& ball.x + BALL_SIZE + ball.dx < brick->x + BRICK_WIDTH)
	{
		return (1);
	}
	return (0);
}

int			collides(t_game *game, int type, t_brick *brick)
{
	t_ball ball;

	ball = game->ball;
	if (type == 1)
		if (test1(brick, ball))
			return (1);
	if (type == 2)
		if (test2(brick, ball))
			return (1);
	if (type == 3)
		if (test3(brick, ball))
			return (1);
	if (type == 4)
		if (test4(brick, ball))
			return (1);
	return (0);
}
