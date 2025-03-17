/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/17 15:24:14 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

// does the map exist, extension.ber
void	check_ber(char *pathname)
{
	int 	len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
		ft_error(ERR_FILE_EXT);
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".ber", 4) != 0)
		ft_error(ERR_FILE_EXT);
}
void	parsing(t_mlx *mlx) // recup nbr de lignes et col + check rectangle
{
	char	*line;
	int		line_length;
	int		current_length;
	
	mlx->map.row_count = 0;
	line = get_next_line(mlx->inputs.fd);
	if (line)
	{
		line_length = ft_strlen(line);
		if (line[line_length - 1] == '\n')
            line_length--;
		mlx->map.col_count = line_length;;
		mlx->map.row_count++;
		free(line);
	}	
	while ((line = get_next_line(mlx->inputs.fd))!= NULL)
	{
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
            current_length--;
		if (current_length != line_length)
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_INVALID); // map pas rectangulaire 
		}
		mlx->map.row_count++;
		free(line);
	}
	close(mlx->inputs.fd);
}

void	allocate_map(t_mlx *mlx)
{
		
}
void	fill_map(t_mlx *mlx)
{
		
}

// faire un compteur avce colonne et lignes pour malloc le tableau 
// malloc la map avec les col et row 
// malloc une fois le tableau et faire une boucle pour reiterer 

// check caractere autorises 

// map enclosed in wall (first and last ligne and colonne, should all be 1)

// only one exit ( count how many E)

// only one start position (count how many P)

// at least one collectible ( count how many ) 




// IF ALL OK 

// exit acessible fom the start pos

// collectible accessible 


// utilisation de flood fill algo, 
//commence au start, et counter pour collectible et exit
// if collectible = colletible when parsing 
// if exit is 0, inaccessble donc invalid 

// donc si tt est ok 
// game beggining 