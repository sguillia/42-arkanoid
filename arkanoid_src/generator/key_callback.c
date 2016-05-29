/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:32:17 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 23:27:17 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

extern int	g_bricktype;

/*
**	Some color bytes are set to "1" because if they are null,
**		collision will not be detected by program
*/

static void	key_colors(int k)
{
	if (k == GLFW_KEY_Q)
		modcolor(255, -1, -1);
	if (k == GLFW_KEY_A)
		modcolor(127, -1, -1);
	if (k == GLFW_KEY_Z)
		modcolor(1, -1, -1);
	if (k == GLFW_KEY_W)
		modcolor(-1, 255, -1);
	if (k == GLFW_KEY_S)
		modcolor(-1, 127, -1);
	if (k == GLFW_KEY_X)
		modcolor(-1, 1, -1);
	if (k == GLFW_KEY_E)
		modcolor(-1, -1, 255);
	if (k == GLFW_KEY_D)
		modcolor(-1, -1, 127);
	if (k == GLFW_KEY_C)
		modcolor(-1, -1, 1);
}

static void	invert_type(void)
{
	g_bricktype = (g_bricktype == 1) ? 2 : 1;
	ft_printf("%cyan;[Info] %yellow;Brick type is now %d\n%;", g_bricktype);
}

void		key_callback(GLFWwindow *w, int k, int s, int action, int mods)
{
	(void)s;
	(void)mods;
	if (action != GLFW_PRESS)
		return ;
	if (k == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(w, GL_TRUE);
	if (k == GLFW_KEY_T)
		invert_type();
	key_colors(k);
}
