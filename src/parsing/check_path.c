/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:46:10 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/20 10:57:48 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

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
int	flood_fill(char **map, int x, int y, char c)
{
	static int cnt = 0;
	// si un mur ou * on stop / condition d'arret du flood fill
	if (map[y][x] == '1' || map[y][x] == '*')
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
	map_e = flood_fill(cp_map, player->p_pos_x, player->p_pos_y, 'E');
	if ( map_e == 0)
		ft_error(ERR_MAP_PATH);
	free_full_tab(mlx, cp_map);
	cp_map = copy_map(mlx);
	map_c = flood_fill(cp_map, player->p_pos_x, player->p_pos_y, 'C') - 1;
	free_full_tab(mlx, cp_map);
	if (map_c != mlx->map.count_c)
		ft_error(ERR_MAP_PATH);
}
