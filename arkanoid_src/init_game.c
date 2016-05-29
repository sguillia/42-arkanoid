/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:04:28 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 20:18:21 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	init_game(t_game *game)
{
	game->lvl = 0;
	if ((game->bricks = get_level(game->lvl)) == NULL)
	{
		ft_putendl_fd("No level was found", 2);
		glfwTerminate();
		exit(-1);
	}
	game->bar.x = WIN_WIDTH / 2;
	game->bar.size = BAR_WIDTH;
	game->bar.sticky_ball = 1;
	game->ball.x = WIN_WIDTH / 2;
	game->ball.y = WIN_HEIGHT - BAR_MARGIN - 25;
	game->ball.dx = 1;
	game->ball.dy = 1;
	game->score = 0;
	game->life = INIT_LIFE;
	game->display = GAME;
	game->playing = 1;
}
