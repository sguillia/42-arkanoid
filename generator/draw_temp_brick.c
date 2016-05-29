/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_temp_brick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:31:49 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 19:51:02 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

extern float	g_color[3];

void	draw_temp_brick(t_game *game)
{
	int mx;
	int my;

	getmousepos(game->window, &mx, &my);
	if (mx < 25 || my < 25
			|| mx > WIN_WIDTH - 25 - BRICK_WIDTH + 9
			|| my > WIN_HEIGHT - BAR_MARGIN - 15 - BRICK_HEIGHT + 9)
		return ;
	setcolor();
	mousemath(&mx, &my);
	mx--;
	glRecti(mx, my, mx + BRICK_WIDTH, my + BRICK_HEIGHT);
}
