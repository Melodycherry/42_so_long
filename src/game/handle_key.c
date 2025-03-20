/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:06:33 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/20 16:28:44 by mlaffita         ###   ########.fr       */
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
	else if () // pour W aller en haut
		// move player 
	else if () // pour S aller en bas
		// move player 
	else if () // pour A aller a gauche
		// move player 
	else if () // pour D aller a droite
		// move player 
	return (0);
}

// faire fonction moveplayer pour gerer les mvmt 
// faire une fonction game quit ?? pour qd echap mais aussi qd tt collectible ok et Exit 

// key handler WASD incrementation du nombre de mvmt fait ?? a mettre qq part ... 