/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:30 by tanas             #+#    #+#             */
/*   Updated: 2023/02/04 20:34:08 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *line)
{
	char	**values;
	int		i;
	int		*x;

	values = ft_split(line, ' ');
	i = 0;
	x = (int *) malloc(sizeof(int));
	while(values[i])
	{
		x[i] = ft_atoi(values[i]);
		i++;
	}
	return (i);
}

int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	free(line);
	height = 0;
	while (line)
	{
		height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (height);
}

int	**get_map(char *file)
{
	int		fd;
	char	*line;
	int		**map;
	int		i;
	t_map	data;

	map = (int **) malloc(sizeof(int *) * (data.height + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	data.width = get_width(line);
	data.height = get_height(file);
	close(fd);
	return (map);
}
