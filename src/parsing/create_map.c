/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:40:13 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/25 12:04:07 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	allocate_map(t_mlx *mlx)
{
	mlx->map.map_tab = (char **) malloc(sizeof(char *) * mlx->map.row_count);
	if (!mlx->map.map_tab)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
}

void	fill_map(t_mlx *mlx)
{
	char	*line;
	int		i;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
		mlx->map.map_tab[i] = ft_strndup(line, mlx->map.line_length);
		if (!mlx->map.map_tab[i])
			free_mid_tab(mlx->map.map_tab, i);
		i++;
		free(line);
	}
	close(mlx->inputs.fd);
}

void	create_map(t_mlx *mlx)
{
	allocate_map(mlx);
	fill_map(mlx);
}
