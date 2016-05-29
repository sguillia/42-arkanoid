/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:52:07 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 22:47:35 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"
#include <sys/stat.h>

extern t_list	*g_bricks;
extern float	g_color[3];
extern int		g_bricktype;

static t_brick	*copy_tbrick(t_brick a)
{
	t_brick	*b;

	check_malloc((b = (t_brick*)malloc(sizeof(*b))));
	b->type = a.type;
	b->solidity = a.solidity;
	b->x = a.x;
	b->y = a.y;
	b->red = a.red;
	b->green = a.green;
	b->blue = a.blue;
	return (b);
}

static void		output_txt(t_brick br)
{
	int fd;

	fd = open("NEWLEVEL", O_CREAT | O_WRONLY | O_APPEND);
	if (fd < 0)
		ft_printf("%red;WARNING: %yellow;Could not open output file !\n%;");
	chmod("NEWLEVEL", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	ft_printf_fd(fd, "%d %d %d %d %d %d %d\n",
			br.type,
			br.solidity,
			br.x,
			br.y,
			(int)(br.red * 255.0),
			(int)(br.green * 255.0),
			(int)(br.blue * 255.0));
	close(fd);
}

static void		add_brick(t_brick br)
{
	t_list	*lst;
	t_brick	*brick;

	check_malloc((lst = ft_lstnew(NULL, 0)));
	brick = copy_tbrick(br);
	lst->content = brick;
	dump_brick(brick);
	ft_lstadd(&g_bricks->next, lst);
	output_txt(br);
}

void			outputme(int x, int y)
{
	t_brick	br;
	int		r;
	int		g;
	int		b;

	r = (int)(255.0 * g_color[0]);
	g = (int)(255.0 * g_color[1]);
	b = (int)(255.0 * g_color[2]);
	br.type = g_bricktype;
	br.solidity = 1;
	br.x = x;
	br.y = y;
	br.red = g_color[0];
	br.green = g_color[1];
	br.blue = g_color[2];
	add_brick(br);
}
