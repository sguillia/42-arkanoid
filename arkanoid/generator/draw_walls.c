/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:06:33 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/30 17:46:33 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	draw_walls(void)
{
	glColor3f(0.5f, 0.5f, 0.5f);
	glRecti(0, 0, 25, WIN_HEIGHT);
	glRecti(0, 0, WIN_WIDTH, 25);
	glRecti(WIN_WIDTH, 0, WIN_WIDTH - 25, WIN_HEIGHT);
}
