/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:28:50 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/17 14:19:29 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_error error)
{
	ft_putstr_fd("Error", STDERR_FILENO);
	if (error == ERR_ARGS)
		ft_putstr_fd(": Need ./so_long and map.ber\n", STDERR_FILENO);
	else if (error == ERR_FILE_EXT)
		ft_putstr_fd(": File must have .ber extension\n", STDERR_FILENO);
	else if ( error == ERR_MAP_INVALID)
		ft_putstr_fd(": Map must be rectangular\n", STDERR_FILENO);
	exit(1);
}
