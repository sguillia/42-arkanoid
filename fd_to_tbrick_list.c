/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_tbrick_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:51:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/30 14:51:05 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

t_list		*fd_to_tbrick_list(int fd)
{
	t_list	*ret;
	char	*line;
	int		gnlret;
	t_brick	*mybrick;

	gnlret = get_next_line(fd, &line);
	if (gnlret != 1)
		return (NULL);
	mybrick = line_to_brick(line);
	free(line);
	if (mybrick)
	{
		check_malloc((ret = ft_lstnew(NULL, 0)));
		ret->content = mybrick;
		ret->next = fd_to_tbrick_list(fd);
		return (ret);
	}
	return (NULL);
}
