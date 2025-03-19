/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/19 16:03:12 by mlaffita         ###   ########.fr       */
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
	int		current_length;
	
	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	mlx->map.row_count = 0;
	mlx->map.line_length = 0;
	line = get_next_line(mlx->inputs.fd);
	if (line)
	{
		mlx->map.line_length = ft_strlen(line);
		if (line[mlx->map.line_length - 1] == '\n')
            mlx->map.line_length--;
		mlx->map.col_count = mlx->map.line_length;
		mlx->map.row_count++;
		free(line);
	}	
	while (1) // diviser la fonction (check_rectangle)
	{
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
            current_length--;
		if (current_length != mlx->map.line_length)
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
	while (1)
	{
		i = 0;
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
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
	char	*line;
	int		i;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	i = 0;
	line = get_next_line(mlx->inputs.fd);
	while ( line[i] != '\0' && line[i] != '\n') // verif 1er ligne
	{
		if (line[i] != '1')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_WALLS);
		}
		i++;
	}
	free(line);
	i = 1;
	while ( i < (mlx->map.row_count - 1)) // middle lines
	{
		line = get_next_line(mlx->inputs.fd);
		if (line[0] != '1' || (line[mlx->map.line_length - 1]) != '1') // premier et dernier char
			{
				free(line);
				close(mlx->inputs.fd);
				ft_error(ERR_MAP_WALLS);
			}
		free(line);
		i++;
	}
	line = get_next_line(mlx->inputs.fd);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n') // verif derniere ligne 
	{
		if (line[i] != '1')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_WALLS);
		}
		i++;
	}
	free(line);
	close(mlx->inputs.fd);
}

// void	allocate_map(t_mlx *mlx)
// {
		
// }
// void	fill_map(t_mlx *mlx)
// {
		
// }

// faire un compteur avce colonne et lignes pour malloc le tableau 
// malloc la map avec les col et row 
// malloc une fois le tableau et faire une boucle pour reiterer 


// IF ALL OK 

// exit acessible fom the start pos
// collectible accessible 


// utilisation de flood fill, 
//commence au start, et counter pour collectible et exit
// if collectible = colletible when parsing 
// if exit is 0, inaccessble donc invalid 

// donc si tt est ok 
// game beggining 