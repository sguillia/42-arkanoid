/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:35:18 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 21:10:15 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	init_gl(t_game *game_info, int ac, char **av)
{
	GLFWmonitor *fs;

	fs = (ac > 1 && !ft_strcmp(av[1], "-fs")) ? glfwGetPrimaryMonitor() : NULL;
	game_info->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT,
			"Arkanoid", fs, NULL);
	if (!game_info->window)
	{
		glfwTerminate();
		exit(1);
	}
	glfwSetKeyCallback(game_info->window, key_callback);
	glfwMakeContextCurrent(game_info->window);
	glfwSetInputMode(game_info->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	game_info->display = MENU;
}
