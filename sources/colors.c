/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:14:32 by tanas             #+#    #+#             */
/*   Updated: 2023/02/22 15:25:30 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**extract_colours(char **values_in_line, t_map map)
{
	int	i;
	int	j;
	int	**colours;

	i = 0;
	j = 0;
	colours = (int **) malloc(sizeof(int *) * map.width);
	if (!colours)
		return (NULL);
	while (values_in_line[i])
	{
		j = 0;
		
		i++;
	}
	return (colours);
}
