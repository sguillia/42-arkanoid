/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:32:49 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/30 17:45:39 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	draw_bar(t_game *game)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glRecti(game->bar.x, WIN_HEIGHT - BAR_MARGIN,
			game->bar.x + BAR_WIDTH, WIN_HEIGHT - BAR_MARGIN - 15);
}
