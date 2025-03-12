/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/12 17:12:33 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// does the map exist

// map rectangulaire ( all the ligen same lenght)

// somethingin the map file

// map enclosed in wall (first and last ligne and colonne, should all be 1)

// only one exit ( count how many E)

// only one start position (count how many P)

// at least one collectible ( count how many ) 

// faire un compteur avce colonne et lignes pour malloc le tableau 


// IF ALL OK 

// exit acessible fom the start pos

// collectible accessible 


// utilisation de flood fill algo, 
//commence au start, et counter pour collectible et exit
// if collectible = colletible when parsing 
// if exit is 0, inaccessble donc invalid 

// donc si tt est ok 
// game beggining 