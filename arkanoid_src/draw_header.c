/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 19:21:19 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 18:57:06 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>

void	draw_header(t_game *game)
{
	int		i;
	int		padding_x;
	char	*score;

	i = -1;
	padding_x = 5;
	glColor3f(1.0f, 0.0f, 0.0f);
	while (++i < game->life)
	{
		glRecti(padding_x, 5, padding_x + BALL_SIZE + 5, 5 + BALL_SIZE + 5);
		padding_x += 25;
	}
	glRasterPos3f(WIN_WIDTH / 2, 20, 0);
	i = 0;
	score = ft_itoa(game->score);
	while (score[i] != '\0')
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
		i++;
	}
	free(score);
}
