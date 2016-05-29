/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <sguillia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 20:28:11 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/30 12:52:56 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

void	*check_malloc(void *content)
{
	if (!content)
	{
		throw_error("Failed to allocate memory", NULL);
		exit(2);
	}
	return (content);
}
