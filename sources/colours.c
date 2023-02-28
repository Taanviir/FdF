/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:14:32 by tanas             #+#    #+#             */
/*   Updated: 2023/02/28 17:21:33 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	*extract_colours(char **values, t_map map)
{
	int		i;
	int		*colours;
	char	**colour;

	colours = (int *) malloc(sizeof(int) * map.width);
	if (!colours)
		return (NULL);
	i = 0;
	while (i < map.width)
	{
		if (!ft_strchr(values[i], 'x'))
			colours[i] = 0xFFFFFF;
		else
		{
			colour = ft_split(values[i], 'x');
			colours[i] = ft_atoi_base(upper(colour[1]), "0123456789ABCDEF");
			free_double_ptr((void **) colour);
		}
		i++;
	}
	return (colours);
}
