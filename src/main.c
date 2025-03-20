/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:28:02 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:30 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx		mlx;
	t_inputs 	*inputs;
	
	if (argc != 2)
		ft_error(ERR_ARGS);
	inputs = &mlx.inputs;
	inputs->pathname = argv[1];
	check_ber(inputs->pathname);
	parsing(&mlx);
	create_map(&mlx);
	check_path(&mlx);
	// si tt ok game beggin 
	mlx.graphic.ptr = mlx_init();
	mlx.graphic.win = mlx_new_window(mlx.graphic.ptr , //col x par ... ?, //row x par ... ?, "So_long");
	//load image ?? recup les xpm
	//draw map ?? mettre les image a chaque element de map 
	// hook et keyhook ??? fonction de la mini libx
	mlx_loop(mlx.graphic.ptr);
	return(0);
}


// void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

