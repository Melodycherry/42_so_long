/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/19 22:56:19 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

char	**copy_map(t_mlx *mlx);
int	flood_fill(char **map, int x, int y, char c);

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
	
	mlx->map.count_p = 0;
	mlx->map.count_e = 0;
	mlx->map.count_c = 0;

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
				mlx->map.count_p++;
			if (line[i] == 'E')
				mlx->map.count_e++;
			if (line[i] == 'C')
				mlx->map.count_c++;
			i++; 
		}
		free(line);
	}
	close(mlx->inputs.fd);
	if (mlx->map.count_p > 1 || mlx->map.count_e > 1 || mlx->map.count_c < 1 )
		ft_error(ERR_MAP_INVALID);
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

void	allocate_map(t_mlx *mlx)
{
	mlx->map.map_tab = (char **)malloc(sizeof(char*) * mlx->map.row_count);
	if (!mlx->map.map_tab)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
}

void	fill_map(t_mlx *mlx)
{
	char	*line;
	int		i;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
		mlx->map.map_tab[i] = ft_strndup(line, mlx->map.line_length);
		if (!mlx->map.map_tab[i])
			free_mid_tab(mlx->map.map_tab, i);
		i++;
		free(line);
	}
	close(mlx->inputs.fd);
}
void	check_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while ( y < mlx->map.row_count)
	{
		x = 0;
		while (x < mlx->map.col_count)
		{
			if (mlx->map.map_tab[y][x] == 'P')
			{
				mlx->map.pos_player.p_pos_x = x;
				mlx->map.pos_player.p_pos_y = y;
				break ;
			}
			x++;
		}
		y++;
	}
	//printf("%d, et %d\n", mlx->map.pos_player.p_pos_y, mlx->map.pos_player.p_pos_x);
}

void	check_path(t_mlx *mlx)
{
	int		map_c;
	int		map_e;
	char	**cp_map;
	t_pos_player	*player;

	map_c = 0;
	map_e = 0;
	player = &mlx->map.pos_player;
	check_player_pos(mlx);
	cp_map = copy_map(mlx);
	map_e = flood_fill(cp_map, player->p_pos_x, player->p_pos_y, 'E'); //e
	printf("%d\n", map_e);
	if ( map_e == 0)
		ft_error(ERR_MAP_PATH);
	free_full_tab(mlx, cp_map);
	cp_map = copy_map(mlx);
	map_c = flood_fill(cp_map, player->p_pos_x, player->p_pos_y, 'C') - 1;// C
	printf("%d\n", map_c);
	free_full_tab(mlx, cp_map);
	// erreur si exit ou collectible pas accessibles 
	if (map_c != mlx->map.count_c)
		ft_error(ERR_MAP_PATH);
}

int	flood_fill(char **map, int x, int y, char c)
{
	static int cnt = 0;
	// si un mur ou * on stop / condition d'arret du flood fill
	if (map[y][x] == '1' || map[y][x] == '*') // double check pour * 
		return (cnt);
	if (map[y][x] == c) // compteur des collectibles et exit 
		cnt++;
	if (map[y][x] != '1') // changer le caractere pour me pas compter qd repasse dessus 
		map[y][x] = '*';
	flood_fill(map, x + 1, y, c);
	flood_fill(map, x - 1, y, c);
	flood_fill(map, x, y + 1, c);
	flood_fill(map, x, y - 1, c);
	return (cnt);
}
	
char	**copy_map(t_mlx *mlx)
{
	int		i;
	char	**cp_map;

	cp_map = (char **)malloc(sizeof(char *) * mlx->map.row_count);
	i = 0;
	while (i < mlx->map.row_count)
	{
		cp_map[i] = ft_strdup(mlx->map.map_tab[i]);	
		if (!cp_map[i])
			free_mid_tab(cp_map, i);
		i++;
	}
	return (cp_map);
}


// donc si tt est ok 
// game beggining 