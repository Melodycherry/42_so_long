/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:33 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 17:58:34 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESCAPE)
		exit_game(mlx);
	else if (keycode == KEY_W)
		player_mvmt(mlx, 0, -1);
	else if (keycode == KEY_S)
		player_mvmt(mlx, 0, 1);
	else if (keycode == KEY_A)
		player_mvmt(mlx, -1, 0);
	else if (keycode == KEY_D)
		player_mvmt(mlx, 1, 0);
	return (0);
}

int	exit_game(t_mlx *mlx)
{
	// int	i;

	// i = 0;
	mlx_destroy_window(mlx->graphic.ptr, mlx->graphic.win);
	// mlx_destroy_image(mlx->graphic.ptr, mlx->graphic.background_img);
	// mlx_destroy_image(mlx->graphic.ptr, mlx->graphic.wall_img);
	// mlx_destroy_image(mlx->graphic.ptr, mlx->graphic.player_img);
	// mlx_destroy_image(mlx->graphic.ptr, mlx->graphic.collectible_img);
	// mlx_destroy_image(mlx->graphic.ptr, mlx->graphic.exit_img);
	// free_mid_tab(mlx->map.map_tab, i);
	// free_full_tab(mlx, mlx->map.map_tab);
	exit(EXIT_SUCCESS);
}
