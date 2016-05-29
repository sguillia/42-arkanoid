/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_shouldwait.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:32:23 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 16:32:25 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

int	framerate_shouldwait(void)
{
	static double	lasttime = 1.0 / (float)FRAMERATE;
	double			nowtime;

	nowtime = glfwGetTime();
	if (nowtime - lasttime >= (1.0 / (float)FRAMERATE))
	{
		lasttime = nowtime;
		return (0);
	}
	return (1);
}
