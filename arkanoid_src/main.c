/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:13:21 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 22:47:55 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static void	change_ortho(void)
{
	glViewport(0, 0, WIN_WIDTH, WIN_HEIGHT);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, WIN_WIDTH, WIN_HEIGHT, 0.0f, 0.0f, 1.0f);
}

static void	handle_event(t_game *game)
{
	int	click;
	int	key;

	click = glfwGetMouseButton(game->window, GLFW_MOUSE_BUTTON_LEFT);
	if (click == GLFW_PRESS)
		game->bar.sticky_ball = 0;
	if (game->display == MENU)
	{
		key = glfwGetKey(game->window, GLFW_KEY_1);
		if (key == GLFW_PRESS)
		{
			game->display = GAME;
			game->playing = 1;
			init_game(game);
		}
		key = glfwGetKey(game->window, GLFW_KEY_2);
		if (key == GLFW_PRESS)
			system("./createlevel.sh");
	}
	if (game->display == LOSE || game->display == WIN)
	{
		key = glfwGetKey(game->window, GLFW_KEY_SPACE);
		if (key == GLFW_PRESS)
			game->display = MENU;
	}
}

int			main(int ac, char **av)
{
	t_game		game_info;

	if (!glfwInit())
		return (-1);
	init_gl(&game_info, ac, av);
	while (!glfwWindowShouldClose(game_info.window))
	{
		if (!framerate_shouldwait())
		{
			handle_event(&game_info);
			change_ortho();
			display(&game_info);
			glfwPollEvents();
			process_game(&game_info);
			glfwSwapBuffers(game_info.window);
		}
	}
	glfwTerminate();
	return (0);
}
