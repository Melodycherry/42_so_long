/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:41:27 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 12:39:20 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// faire fonction pour move du player pour gere les mvmt 
// player_mvt (mlx, x, y) ??? 


void	player_mvmt()
{
	// current position = on l'a deja save player_pos x y
	// new pos = ???
	
	// if new pos == wall '1'
		// ne fait rien ? 
		
	// if new position exit mais que pas total collectible
		// ne fait rien ? 		
		
// if new pos collectible == 'C'
	// current pos mettre background image
	// new pos mettre player image
	// update counter mvmt ?? 
	// update counter collectible dc count_c--  (et qd reach zero ok ?)
		// if tt les collectible collected dc if count_c = 0 ?
			//unlock exit ?? if count_c = 0 then destroy win ? 
		
// if not a wall not a collectible, set player to new pos 
	// also update counter de mouvement ?? 
	

}


// close handler  ??? 
// ne pas oublier de free tt apres close et aussi  chaque mouvement ?? 

// loop hook