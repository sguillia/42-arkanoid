/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:28:49 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 21:24:21 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	display(t_game *game)
{
	draw_walls();
	draw_bar();
	draw_grid();
	draw_brick(game->bricks->next);
	draw_temp_brick(game);
}
