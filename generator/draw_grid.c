/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:20:27 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 21:25:20 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	draw_grid(void)
{
	int x;
	int y;

	glColor3f(0.3f, 0.3f, 0.3f);
	x = 35;
	while (x < WIN_WIDTH - 25)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(x, 25);
		glVertex2i(x, WIN_HEIGHT - BAR_MARGIN - 15);
		glEnd();
		x += 10;
	}
	y = 35;
	while (y < WIN_HEIGHT - BAR_MARGIN - 15)
	{
		glBegin(GL_LINE_LOOP);
		glVertex2i(25, y);
		glVertex2i(WIN_WIDTH - 25, y);
		glEnd();
		y += 10;
	}
}
