/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:09:01 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 11:11:40 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_mlx *mlx)
{
	int width_image;
	int height_image;

	width_image = 160;
	height_image = 160;
	
	mlx->graphic.background_img = mlx_xpm_file_to_image(mlx->graphic.ptr, "src/images/image_xpm/background.xpm", &width_image, &height_image);
	mlx->graphic.wall_img = mlx_xpm_file_to_image(mlx->graphic.ptr, "src/images/image_xpm/block-tile.xpm", &width_image, &height_image);
	mlx->graphic.player_img = mlx_xpm_file_to_image(mlx->graphic.ptr, "src/images/image_xpm/aubergine.xpm", &width_image, &height_image);
	mlx->graphic.exit_img = mlx_xpm_file_to_image(mlx->graphic.ptr, "src/images/image_xpm/peach.xpm", &width_image, &height_image);
	mlx->graphic.collectible_img = mlx_xpm_file_to_image(mlx->graphic.ptr, "src/images/image_xpm/gouttes.xpm", &width_image, &height_image);
}

void	generate_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while ( y < mlx->map.row_count)
	{
		x = 0;
		while ( x < mlx->map.col_count)
		{	
			if (mlx->map.map_tab[y][x] == '1')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.wall_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == '0')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.background_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == 'C')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.collectible_img, x * 160, y * 160);
			else if (mlx->map.map_tab[y][x] == 'E')
				mlx_put_image_to_window(mlx->graphic.ptr, mlx->graphic.win, mlx->graphic.exit_img, x * 160, y * 160);
			x++;
		}
		y++;
	}
}

//Test divers pour afficher window etc ... 

// int	main(void)
// {
// 	t_mlx	mlx;

// 	mlx.mlx_ptr = mlx_init();
// 	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Hello world!");
// 	mlx.mlx_img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
// 	mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel, &mlx.line_length,
// 								&mlx.endian);
// 	mlx_hook(mlx.mlx_win, 2, 1L<<0, handle_key, &mlx);
// 	my_mlx_pixel_put(&mlx, 5, 5, 0x000000FF);
// 	my_mlx_pixel_put(&mlx, 100, 100, 0x00FF0000);
// 	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.mlx_img, 0, 0);
// 	mlx_loop(mlx.mlx_ptr);

// }


