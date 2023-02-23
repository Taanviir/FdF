/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:14:32 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 21:55:11 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	base(int c)
// {
// 	char *str = "0123456789abcdef";
// 	char *str2 = "0123456789ABCDEF";
// 	int  i = 0;

// 	while (i < 16)
// 	{
// 		if (c == str[i] || c == str2[i])
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	ft_atoh(char *str)
// {
// 	int	i;
// 	int	hex;

// 	i = 0;
// 	hex = 0;
// 	while (base(str[i]) != -1)
// 	{
// 		hex *= 16;
// 		hex += base(str[i]);
// 		i++;
// 	}
// 	return (hex);
// }

// int	*extract_colours(char **values, t_map map)
// {
// 	int	i;
// 	int	j;
// 	int	*colours;
// 	char *colour;

// 	i = 0;
// 	colours = (int *) malloc(sizeof(int) * map.width);
// 	if (!colours)
// 		return (NULL);
// 	while (i < map.width)
// 	{
// 		j = 0;
// 		if (ft_strchr(values[i], ','))
// 		{
// 			colours[i] = ft_atoh(colour);
// 		}
// 		else
// 			colours[i] = 0xFFFFFF;
// 		i++;
// 	}
// 	return (colours);
// }
