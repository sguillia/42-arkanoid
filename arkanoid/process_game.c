/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:05:56 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 23:13:52 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static int	count_brick(t_list *brick)
{
	int		i;
	t_brick	*elem;

	i = 0;
	while (brick != NULL)
	{
		elem = brick->content;
		if (elem->type == BRICK_STD)
			i++;
		brick = brick->next;
	}
	return (i);
}

void		process_game(t_game *game)
{
	int	collisiontype;
	int i;

	if (game->playing)
	{
		handle_bar_position(game);
		if (!game->bar.sticky_ball)
		{
			i = -1;
			while (++i < 10)
			{
				if ((collisiontype = future_ball_collision(game)))
				{
					handle_collision(game, collisiontype);
					break ;
				}
				else
					do_ball_motion(game);
			}
		}
		if (game->ball.y > WIN_HEIGHT - BAR_MARGIN + 15)
			reset_game(game);
		if (count_brick(game->bricks->next) == 0)
			change_level(game);
	}
}
