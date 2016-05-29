/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_brick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:35:29 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 21:55:50 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	draw_brick(t_list *bricks)
{
	t_brick	*elem;

	if (bricks != NULL)
	{
		draw_brick(bricks->next);
		elem = bricks->content;
		if (elem->type == BRICK_STD)
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			if (elem->solidity == 3)
				glColor4f(0.1f, 0.1f, 0.1f, 0.1f);
			else if (elem->solidity == 2)
				glColor4f(elem->red, elem->green, elem->blue, 0.4f);
			else
				glColor4f(elem->red, elem->green, elem->blue, 1.0f);
		}
		else
			glColor3f(elem->red, elem->green, elem->blue);
		glRecti(elem->x, elem->y, elem->x
				+ BRICK_WIDTH, elem->y + BRICK_HEIGHT);
		bricks = bricks->next;
	}
}
