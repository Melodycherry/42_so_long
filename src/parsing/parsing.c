/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/16 20:05:31 by mlaffita         ###   ########.fr       */
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
void	parsing(t_mlx *mlx)
{
	char	*line;
	int		i;

	i = 0;
	line = mlx->inputs.map_line;
	while (line[i])
	{
		
	}	
}|
// gnl
// strlen de la 1er ligne 
// struct pour nombre de colonne
// check caractere autorises 
// count a chaque ligne retourner par gnl 
// pr chaque ligne verif que strlen est ientique au strlen de 1er ligne 

// malloc la map avec les col et row 
// malloc une fois le tableau et faire une boucle pour reiterer 


// map rectangulaire ( all the ligen same lenght)

// somethingin the map file

// map enclosed in wall (first and last ligne and colonne, should all be 1)

// only one exit ( count how many E)

// only one start position (count how many P)

// at least one collectible ( count how many ) 

// faire un compteur avce colonne et lignes pour malloc le tableau 


// IF ALL OK 

// exit acessible fom the start pos

// collectible accessible 


// utilisation de flood fill algo, 
//commence au start, et counter pour collectible et exit
// if collectible = colletible when parsing 
// if exit is 0, inaccessble donc invalid 

// donc si tt est ok 
// game beggining 