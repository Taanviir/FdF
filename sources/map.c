/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:30 by tanas             #+#    #+#             */
/*   Updated: 2023/02/22 15:16:08 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// function name is self-explanatory
t_map	get_height_width(char *file)
{
	int		fd;
	char	*line;
	char	**vals;
	t_map	map;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	vals = ft_split(line, ' ');
	map.width = 0;
	while (vals[map.width])
		map.width++;
	free(line);
	map.height = 0;
	while (line)
	{
		map.height++;
		line = get_next_line(fd);
		free(line);
	}
	close(fd);
	return (map);
}

// get_values gets the z values for one line
int	*get_values(char *line, t_map map)
{
	char	**values_str;
	int		*z_values;
	int		i;

	values_str = ft_split(line, ' ');
	map.colours = extract_colours(values_str, map);
	z_values = (int *) malloc(sizeof(int) * map.width);
	if (!z_values)
		return (NULL);
	i = 0;
	while (values_str[i])
	{
		z_values[i] = ft_atoi(values_str[i]);
		free(values_str[i]);
		i++;
	}
	free(values_str);
	return (z_values);
}

// fills up the map with the required z values which can be then
// accessed using the corresponding x, y values
t_map	get_map(char *file)
{
	int		fd;
	char	*line;
	int		i;
	t_map	map;

	map = get_height_width(file);
	map.z_values = (int **) malloc(sizeof(int *) * (map.height + 1));
	if (!map.z_values)
		exit(2);
	i = 0;
	fd = open(file, O_RDONLY);
	while (i < map.height)
	{
		line = get_next_line(fd);
		map.z_values[i] = get_values(line, map);
		free(line);
		i++;
	}
	map.z_values[i] = NULL;
	close(fd);
	return (map);
}
