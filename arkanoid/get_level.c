/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:38:32 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/30 14:53:36 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_list	*get_level(int lvl)
{
	char	*lvl_file;
	char	*lvl_num;
	int		fd;
	t_list	*ret;

	check_malloc((lvl_num = ft_itoa(lvl)));
	check_malloc((lvl_file = ft_strjoin(LEVELS_PREFIX, lvl_num)));
	free(lvl_num);
	fd = open(lvl_file, O_RDONLY);
	free(lvl_file);
	if (fd != -1)
	{
		check_malloc((ret = ft_lstnew(NULL, 0)));
		ret->next = (void*)fd_to_tbrick_list(fd);
		close(fd);
		if (!ret->next)
		{
			free(ret);
			throw_error("input-lvl", "Empty level");
			return (NULL);
		}
		return (ret);
	}
	return (NULL);
}
