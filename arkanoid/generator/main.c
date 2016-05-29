/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:13:21 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 22:31:42 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_list	*g_bricks;
float	g_color[3];
int		g_bricktype;

static void	change_ortho(void)
{
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, WIN_WIDTH, WIN_HEIGHT, 0.0f, 0.0f, 1.0f);
}

int			main(void)
{
	t_game		game;
	int			click;

	if (!glfwInit())
		return (-1);
	init_game(&game);
	init_gl(&game);
	while (!glfwWindowShouldClose(game.window))
	{
		click = glfwGetMouseButton(game.window,
				GLFW_MOUSE_BUTTON_LEFT);
		if (click == GLFW_PRESS)
			game.bar.sticky_ball = 0;
		change_ortho();
		display(&game);
		glfwPollEvents();
		glfwSwapBuffers(game.window);
	}
	glfwTerminate();
	return (0);
}
