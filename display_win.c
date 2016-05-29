/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:20:36 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 22:44:16 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "GLUT/glut.h"

void	display_win(t_game *game)
{
	char	*congrats;
	char	*score;
	char	*press;
	int		i;

	congrats = ft_strdup("Congratulation ! You win !");
	score = ft_strjoin("Final score : ", ft_itoa(game->score));
	press = ft_strdup("Press 'space' to get back to the menu");
	glColor3f(0.7f, 0.7f, 1.0f);
	glRasterPos3f(WIN_WIDTH / 2 - 140, MENU_MARGIN, 0);
	i = -1;
	while (congrats[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, congrats[i]);
	glRasterPos3f(WIN_WIDTH / 2 - 90, WIN_HEIGHT / 2, 0);
	i = -1;
	while (score[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
	i = -1;
	glRasterPos3f(WIN_WIDTH / 2 - 170, WIN_HEIGHT - MENU_ITEM_MARGIN, 0);
	while (press[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, press[i]);
	free(congrats);
	free(score);
	free(press);
}
