/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:41:27 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 11:37:37 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// faire fonction move player pour gere les mvmt 
// move_player (map, x, y) ??? 


void	player_mvmt()
{
	// current position = on l'a deja save player_pos x y
	// new pos = ???
	// if new pos == wall '1'
		// ne fait rien
// if new pos collectible == 'C'
	// change into background dc '0'
	// update counter collectible dc count_c--  et qd reach zero ok ?
	// if tt les collectible collected dc if count_c = 0 ?
		//unlock exit ?? how to do it ??
// if not a wall not a collectible, set player to new pos 
// if new position exit mais que pas total collectible
	// ne fait rien ? 
}


// close handler  ??? 
// ne pas oublier de free tt apres close et aussi  chaque mouvement ?? 

// loop hook