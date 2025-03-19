/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:28:50 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/19 16:06:40 by mlaffita         ###   ########.fr       */
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
	else if ( error == ERR_MAP_SIZE)
		ft_putstr_fd(": Map must be rectangular \n", STDERR_FILENO);
	else if ( error == ERR_MAP_INVALID)
		ft_putstr_fd(": Map invalid (wrong char or too many / few element)\n", STDERR_FILENO);
	else if ( error == ERR_MAP_WALLS)
		ft_putstr_fd(": Map not enclosed with walls\n", STDERR_FILENO);
	else if ( error == ERR_MAP_PATH)
		ft_putstr_fd(": Invalid path (collectible or exit)\n", STDERR_FILENO);
	exit(1);
}
void	*free_ptr(void **ptr)
{
	if (ptr && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}
void	flood_fill()
{

//commence au start, et counter pour collectible et exit
// if collectible = colletible when parsing 
// if exit is 0, inaccessble donc invalid 
	if ()
	
}
