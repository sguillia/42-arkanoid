/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguillia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:27:08 by sguillia          #+#    #+#             */
/*   Updated: 2016/01/30 12:35:14 by sguillia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arkanoid.h"

/*
**	The return value should not be modified
**	If it is anyway, all calling functions should be checked
*/

int		throw_error(char *cmd, char *subcmd)
{
	if (subcmd)
		ft_printf_fd(2, "arkanoid: %s: %s\n",
				cmd, subcmd);
	else
		ft_printf_fd(2, "arkanoid: %s\n", cmd);
	return (1);
}
