/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:04:28 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 22:45:56 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

extern t_list	*g_bricks;
extern float	g_color[3];
extern int		g_bricktype;

static void	welcome(void)
{
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("~~~ %cyan;Welcome in arkanoid level generator !%; ~~~\n");
	ft_printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	ft_printf("Use key T to change block type \
(standard vs. nonbreak)\n");
	ft_printf("Use the following keys to change colors :\n");
	ft_printf("Q W E - 255\n");
	ft_printf("A S D - 127\n");
	ft_printf("Z X C - 0\n");
	ft_printf("| | |\n");
	ft_printf("%red;R%; %green;G%; %cyan;B%;\n");
	ft_printf("Output level will be text file %red;NEWLEVEL%;\n");
	ft_printf("Bricks will be appended\n");
	ft_printf("Authors: %cyan;mdeken%; and %cyan;sguillia%;\n");
	ft_printf("~~~ %cyan;Have fun !%; ~~~\n");
}

void		init_game(t_game *game)
{
	game->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT,
			"Arkanoid level generator", NULL, NULL);
	if (!game->window)
	{
		glfwTerminate();
		exit(1);
	}
	check_malloc((game->bricks = ft_lstnew(NULL, 0)));
	g_bricks = game->bricks;
	g_color[0] = 1.0f;
	g_color[1] = 0.0f;
	g_color[2] = 0.0f;
	g_bricktype = 1;
	welcome();
}
