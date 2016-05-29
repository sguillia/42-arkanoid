/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bar_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:15:05 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 16:28:34 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	handle_bar_position(t_game *game)
{
	double	mouse_x;
	double	bar_half_width;

	bar_half_width = (float)BAR_WIDTH / 2.0;
	glfwGetCursorPos(game->window, &mouse_x, NULL);
	if (mouse_x < 25.0 + bar_half_width)
		mouse_x = 25.0 + bar_half_width;
	if (mouse_x > WIN_WIDTH - 25 - bar_half_width)
		mouse_x = WIN_WIDTH - 25 - bar_half_width;
	game->bar.x = mouse_x - bar_half_width;
	if (game->bar.sticky_ball)
		game->ball.x = mouse_x;
}
