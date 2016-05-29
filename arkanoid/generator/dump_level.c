/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:24:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 23:03:43 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	dump_brick(t_brick *brick)
{
	ft_printf("Brick [type=%magenta;%03d%; solidity=%magenta;%03d%; \
x=%magenta;%04d%; y=%magenta;%04d%; %red;red=%03d %green;green=%03d \
%cyan;blue=%03d %;]\n",
			brick->type,
			brick->solidity,
			brick->x,
			brick->y,
			(int)(255.0 * brick->red),
			(int)(255.0 * brick->green),
			(int)(255.0 * brick->blue));
}

void	dump_level(t_list *lvl)
{
	ft_putendl("Dumping level");
	lvl = lvl->next;
	while (lvl)
	{
		dump_brick(lvl->content);
		lvl = lvl->next;
	}
}
