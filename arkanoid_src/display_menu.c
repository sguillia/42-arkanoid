/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeken <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:10:49 by mdeken            #+#    #+#             */
/*   Updated: 2016/01/31 19:45:01 by mdeken           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include "GLUT/glut.h"

void	display_menu(t_game *game)
{
	char	*play;
	char	*editor;
	char	*exit;
	int		i;

	(void)game;
	play = ft_strdup("1 - Play");
	editor = ft_strdup("2 - Level Editor");
	exit = ft_strdup("Esc - Quit");
	glColor3f(0.7f, 0.7f, 1.0f);
	glRasterPos3f(WIN_WIDTH / 2, MENU_MARGIN, 0);
	i = -1;
	while (play[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, play[i]);
	i = -1;
	glRasterPos3f(WIN_WIDTH / 2 - 25, MENU_MARGIN + MENU_ITEM_MARGIN, 0);
	while (editor[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, editor[i]);
	i = -1;
	glRasterPos3f(WIN_WIDTH / 2, MENU_MARGIN + (MENU_ITEM_MARGIN * 2), 0);
	while (exit[++i] != '\0')
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, exit[i]);
	free(play);
	free(editor);
	free(exit);
}
