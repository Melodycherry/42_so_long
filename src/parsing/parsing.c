/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:22:36 by mlaffita          #+#    #+#             */
/*   Updated: 2025/03/20 12:35:15 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	check_ber(char *pathname)
{
	int 	len;
	char	*extension;

	len = ft_strlen(pathname);
	if (len < 4)
		ft_error(ERR_FILE_EXT);
	extension = pathname + (len - 4);
	if (ft_strncmp(extension, ".ber", 4) != 0)
		ft_error(ERR_FILE_EXT);
}
void	check_characters(char *line, t_mlx *mlx)
{
	int		i;
	
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' && line[i] != 'E' && line[i] != 'C' && line[i] != '\n')
		{
			free(line);
			close(mlx->inputs.fd);
			ft_error(ERR_MAP_INVALID);
		}
		i++; 
	}
}
void	update_count(char *line, t_mlx *mlx)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'P')
			mlx->map.count_p++;
		if (line[i] == 'E')
			mlx->map.count_e++;
		if (line[i] == 'C')
			mlx->map.count_c++;
		i++;
	}
}
void	check_pec(t_mlx *mlx)
{
	char	*line;
	
	mlx->map.count_p = 0;
	mlx->map.count_e = 0;
	mlx->map.count_c = 0;

	mlx->inputs.fd = open(mlx->inputs.pathname, O_RDONLY);
	if (mlx->inputs.fd == -1)
		perror(NULL);
	while (1)
	{
		line = get_next_line(mlx->inputs.fd);
		if (line == NULL)
			break ;
		check_characters(line, mlx);
		update_count(line, mlx);
		free(line);
	}
	close(mlx->inputs.fd);
	if (mlx->map.count_p != 1 || mlx->map.count_e != 1 || mlx->map.count_c < 1 )
		ft_error(ERR_MAP_INVALID);
}
void	parsing(t_mlx *mlx)
{
	check_rectangle(mlx);
	check_pec(mlx);
	check_wall(mlx);
}
