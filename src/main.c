/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:28:02 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/21 17:33:53 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_map(t_mlx *mlx);

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
	mlx.graphic.win = mlx_new_window(mlx.graphic.ptr , mlx.map.col_count * 160, mlx.map.row_count * 160, "Sexy PacMan");
	load_image(&mlx);
	generate_map(&mlx);
	//print_map(&mlx); // pour verif pourquoi il print que des collectible
	mlx_put_image_to_window(&mlx, mlx.graphic.win, mlx.graphic.player_img, mlx.map.pos_player.p_pos_x * 160, mlx.map.pos_player.p_pos_y * 160); // seems ok
	// hook et keyhook ??? fonction de la mini libx a checker
	mlx_loop(mlx.graphic.ptr);
	return(0);
}


// void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void print_map(t_mlx *mlx)
{
	int i;

	i = 0;
	printf("\n");
	while (i < mlx->map.row_count)
		printf("%s\n", mlx->map.map_tab[i++]);
}