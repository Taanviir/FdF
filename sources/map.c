/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:32:30 by tanas             #+#    #+#             */
/*   Updated: 2023/02/05 23:38:12 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* 
	make function that checks values_str for hexa code
	if found then get colour
	atoi and input the number value into values_int
	get hexa color code */

// get_values does two things; gets the z values for one line and gets the width
t_map	get_values(char *line, int index, t_map map)
{
	char	**values_str;
	int		i;

	values_str = ft_split(line, ' ');
	map.z_values = (int **) malloc(sizeof(int *) * map.height);
	if (!map.z_values)
		exit(2);
	map.z_values[index] = malloc(sizeof(int) * map.width);
	if (!map.z_values[index])
		exit(3);
	i = 0;
	while (values_str[i])
	{
		map.z_values[index][i] = ft_atoi(values_str[i]);
		i++;
	}
	free(values_str);
	return (map);
}

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

t_map	get_map(char *file)
{
	int		fd;
	char	*line;
	int		j;
	t_map	map;

	map = get_height_width(file);
	j = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (j < map.height)
	{
		map = get_values(line, j, map);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	close(fd);	
	return (map);
}
