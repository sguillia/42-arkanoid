/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:28:08 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 20:00:30 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	reset_game(t_game *game)
{
	if (game->life > 0)
	{
		game->bar.size = BAR_WIDTH;
		game->bar.sticky_ball = 1;
		game->ball.x = (game->bar.x + game->bar.x + BAR_WIDTH) / 2;
		game->ball.y = WIN_HEIGHT - BAR_MARGIN - 25;
		game->ball.dx = 1;
		game->ball.dy = -1;
		game->life -= 1;
	}
	else
	{
		game->playing = 0;
		game->display = LOSE;
	}
}
