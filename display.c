/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 16:28:49 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 22:36:38 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	display(t_game *game)
{
	if (game->display == GAME)
		display_game(game);
	else if (game->display == MENU)
		display_menu(game);
	else if (game->display == LOSE)
		display_lose(game);
	else if (game->display == WIN)
		display_win(game);
}
