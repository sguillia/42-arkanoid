/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:16:48 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 16:17:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int		ball_motion(t_game *game, char *str)
{
	int dx;
	int dy;

	dx = game->ball.dx;
	dy = game->ball.dy;
	if (*str == 'U' && dy < 0)
		return (1);
	else if (*str == 'D' && dy > 0)
		return (1);
	else if (*str == 'L' && dx < 0)
		return (1);
	else if (*str == 'R' && dx > 0)
		return (1);
	else
		return (0);
}
