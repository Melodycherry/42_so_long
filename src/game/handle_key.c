/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:33 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 12:43:30 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESCAPE) // faire aussi avec clic souris sur la croix ?? 
	{
		mlx_destroy_window(mlx->graphic.ptr, mlx->graphic.win);
		exit(EXIT_SUCCESS);
	}
	// else if (keycode == KEY_W) // pour W aller en haut
	// // 	// player_mvmt( map, x, y) ?? mettre + 1 ou - 1 pour changer pos
	// else if (keycode == KEY_S) // pour S aller en bas
	// // 	// player_mvmt
	// else if (keycode == KEY_A) // pour A aller a gauche
	// // 	// player_mvmt
	// else if (keycode == KEY_D) // pour D aller a droite
	// // 	// player_mvmt
	return (0);
}

// faire fonction pour gerer les mvmt ?? avec 3 parametre ( la map, x, y) ??? 
// faire une fonction game quit ?? pour qd echap mais aussi qd tt collectible ok et Exit 

// key handler WASD incrementation du nombre de mvmt fait ?? a mettre qq part ... 