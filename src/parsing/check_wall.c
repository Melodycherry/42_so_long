/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:28:04 by mlaffita          #+#    #+#             */
/*   Updated: 2025/11/13 14:54:53 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	rec_first_line(char *line, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_WALLS);
		}
		i++;
	}
}

void	rec_middle_line(char *line, t_mlx *mlx)
{
	int		i;

	i = 1;
	while (i < (mlx->map.row_count - 1))
	{
		line = get_next_line(mlx->inputs.fd);
		if (line[0] != '1' || (line[mlx->map.line_length - 1]) != '1')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_WALLS);
		}
		free(line);
		i++;
	}
}

void	rec_last_line(char *line, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_WALLS);
		}
		i++;
	}
}

void	check_wall(t_mlx *mlx)
{
	char	*line;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	line = get_next_line(mlx->inputs.fd);
	rec_first_line(line, mlx);
	//free(line);
	rec_middle_line(line, mlx);
	line = get_next_line(mlx->inputs.fd);
	rec_last_line(line, mlx);
	free(line);
	close(mlx->inputs.fd);
}
