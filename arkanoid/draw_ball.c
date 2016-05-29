/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:03:21 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 21:54:59 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	draw_ball(t_game *game)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glRecti(game->ball.x, game->ball.y,
			game->ball.x + BALL_SIZE, game->ball.y + BALL_SIZE);
}
