/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:09:45 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 17:53:03 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "keycodes.h"
# include "X11_events.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>


//Structure

typedef struct s_graphic
{
	void	*ptr;
	void	*win;
	void	*background_img;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*collectible_img;
	int		line_length;
}	t_graphic;

typedef struct s_inputs
{
	char	*pathname;
	int		fd;
	char	*map_line;
}	t_inputs;

typedef	struct pos_player
{
	int	p_pos_y;
	int	p_pos_x;
}t_pos_player;

typedef struct	s_map
{
	int		col_count;
	int		row_count;
	int		line_length;
	int		count_p;
	int		count_e;
	int		count_c;
	int		count_mvmt;
	char	**map_tab;
	t_pos_player	pos_player;
}t_map;

typedef struct	s_mlx 
{
	t_graphic		graphic;
	t_inputs		inputs;
	t_map			map;
}				t_mlx;


typedef enum e_error
{
	ERR_ARGS,
	ERR_FILE_EXT,
	ERR_MAP_INVALID_CHAR,
	ERR_MAP_INVALID,
	ERR_MAP_SIZE,
	ERR_MAP_WALLS,
	ERR_MAP_PATH,
} t_error;

//Parsing
void	check_ber(char *pathname);
void	check_pec(t_mlx *mlx);
void	check_wall(t_mlx *mlx);
void	rec_first_line(char *line, t_mlx *mlx);
void	rec_middle_line(char *line, t_mlx *mlx);
void	rec_last_line(char *line, t_mlx *mlx);
void	check_rectangle(t_mlx *mlx);
void	check_characters(char *line, t_mlx *mlx);
void	update_count(char *line, t_mlx *mlx);
void	parsing(t_mlx *mlx);
void	allocate_map(t_mlx *mlx);
void	fill_map(t_mlx *mlx);
void	create_map(t_mlx *mlx);
void	check_player_pos(t_mlx *mlx);
void	check_path(t_mlx *mlx);
int		flood_fill(char **map, int x, int y, char c);
char	**copy_map(t_mlx *mlx);

//utils
void	ft_error(t_error error);
void	*free_ptr(void **ptr);
char    *free_mid_tab(char **strs, int i);
char    *free_full_tab(t_mlx *mlx, char **tab);
void	*my_load_image(t_mlx *mlx, char *filename);
void	my_put_image_at(t_mlx *mlx, void *image, int x, int y);

//Game
int		handle_key(int keycode, t_mlx *mlx);
void	load_image(t_mlx *mlx);
void	generate_map(t_mlx *mlx);
int		exit_game(t_mlx *mlx);
void	player_mvmt(t_mlx *mlx, int x, int y);
#endif