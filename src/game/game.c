/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:41:27 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 18:59:35 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_mvmt(t_mlx *mlx, int x, int y)
{
	t_map			*map;
	t_pos_player	old_pos;
	t_pos_player	*player;

	map = &mlx->map;
	player = &mlx->map.pos_player;

	if (map->map_tab[player->p_pos_y + y][player->p_pos_x + x] != '1')
	{	
		map->count_mvmt++;
		old_pos = mlx->map.pos_player;
		mlx->map.pos_player.p_pos_x = mlx->map.pos_player.p_pos_x + x;
		mlx->map.pos_player.p_pos_y = mlx->map.pos_player.p_pos_y + y;
		mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.background_img, old_pos.p_pos_x * 160, old_pos.p_pos_y * 160);
		mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.player_img, mlx->map.pos_player.p_pos_x * 160, mlx->map.pos_player.p_pos_y * 160);
		if (map->map_tab[player->p_pos_y][player->p_pos_x] == 'C')
		{
			map->map_tab[player->p_pos_y][player->p_pos_x] = '0';
			mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.background_img, old_pos.p_pos_x * 160, old_pos.p_pos_y * 160);
			mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.player_img, mlx->map.pos_player.p_pos_x * 160, mlx->map.pos_player.p_pos_y * 160);
			mlx->map.count_c--;
			
		} 
		if (map->map_tab[player->p_pos_y][player->p_pos_x] == 'E')
		{	
			if (mlx->map.count_c == 0)
				exit_game(mlx);
		} 
		if ( map->map_tab[old_pos.p_pos_y][old_pos.p_pos_x] == 'E')
			mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.exit_img, old_pos.p_pos_x * 160, old_pos.p_pos_y * 160);
		ft_printf("Move count: %d\n", map->count_mvmt);
	}
}

void	for_c()
{
	
}

void	for_e()
{
	
}
