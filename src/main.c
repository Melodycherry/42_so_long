/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:28:02 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:16 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// int	main(void)
// {
	
// }



int	handle_key(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESCAPE)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "Hello world!");
	mlx.mlx_img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);
	mlx.addr = mlx_get_data_addr(mlx.mlx_img, &mlx.bits_per_pixel, &mlx.line_length,
								&mlx.endian);
	mlx_hook(mlx.mlx_win, 2, 1L<<0, handle_key, &mlx);
	my_mlx_pixel_put(&mlx, 5, 5, 0x000000FF);
	my_mlx_pixel_put(&mlx, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_loop(mlx.mlx_ptr);

}