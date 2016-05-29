/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:07:26 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 20:05:33 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
	int		mx;
	int		my;

	(void)window;
	(void)mods;
	if (action != GLFW_PRESS || button != 0)
		return ;
	getmousepos(window, &mx, &my);
	if (mx < 25 || my < 25
			|| mx > WIN_WIDTH - 25 - BRICK_WIDTH + 9
			|| my > WIN_HEIGHT - BAR_MARGIN - 15 - BRICK_HEIGHT + 9)
		return ;
	mousemath(&mx, &my);
	outputme(mx, my);
}
