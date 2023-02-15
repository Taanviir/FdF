/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:30 by tanas             #+#    #+#             */
/*   Updated: 2023/02/15 22:20:45 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
	make function that checks values_str for hexa code
	if found then get colour
	atoi and input the number value into values_int
	get hexa color code */

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

// get_values does two things; gets the z values for one line and gets the width
int	*get_values(char *line, t_map map)
{
	char	**values_str;
	int		*z_values;
	int		i;

	values_str = ft_split(line, ' ');
	z_values = malloc(sizeof(int) * map.width);
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
