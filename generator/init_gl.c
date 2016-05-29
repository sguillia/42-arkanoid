/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:35:18 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 19:07:07 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	init_gl(t_game *game_info)
{
	glfwSetKeyCallback(game_info->window, key_callback);
	glfwSetMouseButtonCallback(game_info->window, mouse_callback);
	glfwMakeContextCurrent(game_info->window);
}
