/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modcolor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:09:19 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 21:27:08 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

extern float	g_color[3];

void	modcolor(int r, int g, int b)
{
	if (r >= 0)
		g_color[0] = (float)r / 255.0;
	if (g >= 0)
		g_color[1] = (float)g / 255.0;
	if (b >= 0)
		g_color[2] = (float)b / 255.0;
}
