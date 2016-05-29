/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_brick.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 13:10:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/31 21:11:58 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

static t_brick	*copy_tbrick(t_brick a)
{
	t_brick	*b;

	if (!a.type || !a.solidity || !a.x || !a.y)
	{
		throw_error("lvl-input", "One of the values is zero");
		return (NULL);
	}
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

static int		valid_lengths(char **tab)
{
	while (*tab)
	{
		if (ft_strlen(*tab) > 4)
			return (0);
		tab++;
	}
	return (1);
}

static float	color_i_to_f(int color)
{
	float ret;

	if (color > 255)
		color = 255;
	ret = (float)color / 255.0;
	return (ret);
}

t_brick			*line_to_brick(char *line)
{
	t_brick		ret;
	char		**tab;

	check_malloc((tab = ft_strsplit(line, ' ')));
	if (ft_tablen(tab) != 7 || !valid_lengths(tab))
	{
		throw_error("input-lvl", "tablen != 7 || strlen > 4");
		ft_free_tab(tab);
		return (NULL);
	}
	ret.type = ft_abs(ft_atoi(tab[0]));
	ret.solidity = ft_abs(ft_atoi(tab[1]));
	ret.x = ft_abs(ft_atoi(tab[2]));
	ret.y = ft_abs(ft_atoi(tab[3]));
	ret.red = color_i_to_f(ft_abs(ft_atoi(tab[4])));
	ret.green = color_i_to_f(ft_abs(ft_atoi(tab[5])));
	ret.blue = color_i_to_f(ft_abs(ft_atoi(tab[6])));
	ft_free_tab(tab);
	return (copy_tbrick(ret));
}
