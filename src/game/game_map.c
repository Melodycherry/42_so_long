/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:09:01 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 12:09:38 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_mlx *mlx)
{
	int	width_image;
	int	height_image;

	width_image = 160;
	height_image = 160;
	mlx->graphic.background_img = mlx_xpm_file_to_image(mlx->graphic.ptr,
			"src/images/image_xpm/background.xpm", &width_image, &height_image);
	mlx->graphic.wall_img = mlx_xpm_file_to_image(mlx->graphic.ptr,
			"src/images/image_xpm/block-tile.xpm", &width_image, &height_image);
	mlx->graphic.player_img = mlx_xpm_file_to_image(mlx->graphic.ptr,
			"src/images/image_xpm/aubergine.xpm", &width_image, &height_image);
	mlx->graphic.exit_img = mlx_xpm_file_to_image(mlx->graphic.ptr,
			"src/images/image_xpm/peach.xpm", &width_image, &height_image);
	mlx->graphic.collectible_img = mlx_xpm_file_to_image(mlx->graphic.ptr,
			"src/images/image_xpm/gouttes.xpm", &width_image, &height_image);
}

void	generate_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->map.row_count)
	{
		x = 0;
		while (x < mlx->map.col_count)
		{	
			if (mlx->map.map_tab[y][x] == '1')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win,
					mlx->graphic.wall_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == '0')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win,
					mlx->graphic.background_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == 'C')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win,
					mlx->graphic.collectible_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == 'E')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win,
					mlx->graphic.exit_img, x * 160, y * 160);
			x++;
		}
		y++;
	}
}
