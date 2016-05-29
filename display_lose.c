/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lose.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:53:42 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 20:14:44 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "GLUT/glut.h"
#include "libft.h"

void	display_lose(t_game *game)
{
	char	*lose;
	char	*score;
	char	*press;
	int		i;

	lose = ft_strdup("You lost the game !");
	score = ft_strjoin("Final score : ", ft_itoa(game->score));
	press = ft_strdup("Press 'space' to get back to the menu");
	glColor3f(0.7f, 0.7f, 1.0f);
	glRasterPos3f(WIN_WIDTH / 2 - 100, MENU_MARGIN, 0);
	i = -1;
	while (lose[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lose[i]);
	glRasterPos3f(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2, 0);
	i = -1;
	while (score[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
	glRasterPos3f(WIN_WIDTH / 2 - 170, WIN_HEIGHT - MENU_ITEM_MARGIN, 0);
	i = -1;
	while (press[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, press[i]);
	free(press);
	free(lose);
	free(score);
}
