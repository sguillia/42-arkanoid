/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmousepos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:36:57 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 21:26:42 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	getmousepos(GLFWwindow *window, int *mx, int *my)
{
	double mousex;
	double mousey;

	glfwGetCursorPos(window, &mousex, &mousey);
	*mx = (int)mousex;
	*my = (int)mousey;
}
