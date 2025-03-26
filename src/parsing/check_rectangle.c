/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:56:56 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/26 16:01:55 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	check_first_line(t_mlx *mlx)
{
	char	*line;

	line = get_next_line(mlx->inputs.fd);
	if (line)
	{
		mlx->map.line_length = ft_strlen(line);
		if (line[mlx->map.line_length - 1] == '\n')
			mlx->map.line_length--;
		mlx->map.col_count = mlx->map.line_length;
		mlx->map.row_count++;
		free(line);
	}
	if (mlx->map.line_length > 24)
		ft_error(ERR_MAP_INVALID);
}

void	check_other_lines(t_mlx *mlx)
{
	char	*line;
	int		current_length;	

	while (1)
	{
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
			current_length--;
		if (current_length != mlx->map.line_length)
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_SIZE);
		}
		mlx->map.row_count++;
		free(line);
		if (mlx->map.row_count > 13)
			ft_error(ERR_MAP_INVALID);
	}
}

void	check_rectangle(t_mlx *mlx)
{
	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
	{
		perror(NULL);
		ft_error(ERR_MAP_NOT_FOUND);
	}
	mlx->map.row_count = 0;
	mlx->map.line_length = 0;
	check_first_line(mlx);
	check_other_lines(mlx);
	close(mlx->inputs.fd);
}
