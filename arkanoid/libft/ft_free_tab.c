/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:21:33 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/29 15:22:32 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **mytab)
{
	int i;

	i = -1;
	while (mytab[++i])
		free(mytab[i]);
	free(mytab);
	return (NULL);
}