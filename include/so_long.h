/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:09:45 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/16 19:44:22 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "keycodes.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>


//Structure

typedef struct s_graphic
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_graphic;

typedef struct s_inputs
{
	char	*pathname;
	int		fd;
	char	*map_line;
}	t_inputs;

typedef struct	s_map
{
	int		col;
	int		row;
	int		player;
	int		exit;
	char	**map;
}t_map;


typedef struct	s_mlx 
{
	t_graphic	graphic;
	t_inputs	inputs;
	t_map		map;
}				t_mlx;

// faire stucture graphic / map (tableau 2D, char, count colonne et row) /


typedef enum e_error
{
	ERR_ARGS,
	ERR_FILE_EXT,
	ERR_MAP_INVALID,
	ERR_MAP_CHARS,
	ERR_MAP_WALLS, // ajouter exit , start, collectible ???
} t_error;

//Parsing
void	check_ber(char *pathname);

//utils
void	ft_error(t_error error);

#endif