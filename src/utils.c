/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:28:50 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 10:25:50 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_error error)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error == ERR_ARGS)
		ft_putstr_fd("Need ./so_long and map.ber\n", STDERR_FILENO);
	else if (error == ERR_FILE_EXT)
		ft_putstr_fd("File must have .ber extension\n", STDERR_FILENO);
	else if ( error == ERR_MAP_SIZE)
		ft_putstr_fd("Map must be rectangular \n", STDERR_FILENO);
	else if ( error == ERR_MAP_INVALID)
		ft_putstr_fd("Map invalid (too many / few element)\n", STDERR_FILENO);
	else if ( error == ERR_MAP_INVALID_CHAR)
		ft_putstr_fd("Map invalid (wrong char)\n", STDERR_FILENO);
	else if ( error == ERR_MAP_WALLS)
		ft_putstr_fd("Map not enclosed with walls\n", STDERR_FILENO);
	else if ( error == ERR_MAP_PATH)
		ft_putstr_fd("Invalid path (collectible or exit)\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
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
char    *free_mid_tab(char **strs, int i)
{
    while (i > 0)
        free (strs[--i]);
    free(strs);
    return (NULL);
}

char    *free_full_tab(t_mlx *mlx, char **tab)
{
	int i;
	
	i = 0;
    while (i < mlx->map.row_count)
        free (tab[i++]);
    free(tab);
    return (NULL);
}
