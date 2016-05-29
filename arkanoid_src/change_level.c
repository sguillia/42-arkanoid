/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:28:25 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 22:38:05 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	change_level(t_game *game)
{
	game->lvl += 1;
	game->bricks = get_level(game->lvl);
	game->playing = 0;
	if (game->bricks == NULL)
		game->display = WIN;
	else
	{
		game->bar.sticky_ball = 1;
		game->ball.x = (game->bar.x + game->bar.x + BAR_WIDTH) / 2;
		game->ball.y = WIN_HEIGHT - BAR_MARGIN - 25;
		game->ball.dx = 1;
		game->ball.dy = 1;
	}
}
