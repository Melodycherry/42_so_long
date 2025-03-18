/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/18 17:40:14 by mlaffita         ###   ########.fr       */
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
	
	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
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
	while ((line = get_next_line(mlx->inputs.fd))!= NULL) // diviser la fonction (is_rectangle)
	{
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
            current_length--;
		if (current_length != line_length)
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_SIZE); // map pas rectangulaire 
		}
		mlx->map.row_count++;
		free(line); 
	}
	close(mlx->inputs.fd);
}

void	check_pec(t_mlx *mlx) // checker player, exit, collectible, et aussi 1 et 0 
{
	char	*line;
	int		i;
	int		count_p;
	int		count_e;
	int		count_c; // on va utiliser le nbr de collectible pour le flood fill ? a mettre tt dans une struct ? 
	
	count_p = 0;
	count_e = 0;
	count_c = 0;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
    if (mlx->inputs.fd == -1)
        perror(NULL);
	while ((line = get_next_line(mlx->inputs.fd))!= NULL)
	{
		i = 0;
		while (line[i] != '\0')
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E' && line[i] != 'C' && line[i] != '\n')
			{
				free(line);
				close(mlx->inputs.fd);
				ft_error(ERR_MAP_INVALID);
			}
			if (line[i] == 'P')
				count_p++;
			if (line[i] == 'E')
				count_e++;
			if (line[i] == 'C')
				count_c++;
			i++; 
		}
		free(line);
	}
	close(mlx->inputs.fd);
	if (count_p > 1 || count_e > 1 || count_c < 1 )
		ft_error(ERR_MAP_INVALID);
	printf("player : %d, exit: %d, collectible %d\n", count_p, count_e, count_c);
}

void	check_wall(t_mlx *mlx)
{
	// first line = 1
	// last line = 1
	// premier caractere de ligne 1
	// dernier caractere de ligne 1
	// sinon retourne ERR_MAP_WALLS
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