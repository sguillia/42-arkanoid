/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 20:29:59 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 16:51:20 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void		handle_collision(t_game *game, int type)
{
	t_list		*lst;
	t_brick		*mybrick;
	t_list		*tmpnext;

	lst = game->bricks;
	while (lst && lst->next)
	{
		mybrick = (t_brick*)lst->next->content;
		if (collides(game, type, mybrick))
		{
			if (mybrick->type == BRICK_STD)
			{
				if (--mybrick->solidity == 0)
				{
					free(mybrick);
					tmpnext = lst->next->next;
					free(lst->next);
					lst->next = tmpnext;
					game->score += 50;
				}
			}
		}
		lst = lst->next;
	}
	reverse_deltas(game, type);
}
