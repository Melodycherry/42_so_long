/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:33 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/20 17:36:58 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	//printf("%d\n", keycode);
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(mlx->graphic.ptr, mlx->graphic.win); // a checker ? fix copilot 
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W) // pour W aller en haut
		// move player ( map, x, y) ?? mettre + 1 ou - 1 pour changer pos
	else if (keycode == KEY_S) // pour S aller en bas
		// move player 
	else if (keycode == KEY_A) // pour A aller a gauche
		// move player 
	else if (keycode == KEY_D) // pour D aller a droite
		// move player 
	return (0);
}

// faire fonction moveplayer pour gerer les mvmt ?? avec 3 parametre ( map, x, y) ??? 
// faire une fonction game quit ?? pour qd echap mais aussi qd tt collectible ok et Exit 

// key handler WASD incrementation du nombre de mvmt fait ?? a mettre qq part ... 