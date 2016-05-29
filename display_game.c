/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:07:35 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 19:16:05 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	display_game(t_game *game)
{
	draw_brick(game->bricks->next);
	draw_walls();
	draw_bar(game);
	draw_ball(game);
	draw_header(game);
}
