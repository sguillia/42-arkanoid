/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:32:49 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 18:49:40 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <GLFW/glfw3.h>

void	draw_bar(void)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glRecti(25, WIN_HEIGHT - BAR_MARGIN,
			WIN_WIDTH - 25, WIN_HEIGHT - BAR_MARGIN - 15);
}
