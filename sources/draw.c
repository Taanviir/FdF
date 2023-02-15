/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/15 22:29:01 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(int x, int y, t_map map)
{
	t_point	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = map.z_values[y][x];
	return (new_point);
}

void	draw(t_map map, t_img image)
{
	t_point	point;

	point.y = 0;
	point.x = 0;
	while (point.y < map.height)
	{
		point.x = 0;
		while (point.x < map.width)
		{
			if (point.x < (map.width - 1))
				draw_line(new_point(point.x, point.y, map), new_point(point.x + 1, point.y, map), image);
			if (point.y < (map.height - 1))
				draw_line(new_point(point.x, point.y, map), new_point(point.x, point.y + 1, map), image);
			point.x++;
		}
		point.y++;
	}
	if ((point.y == map.height) && (point.x == map.width))
		my_pixel_put(image, (point.x - 1) * 50, (point.y - 1) * 50, 0x00FF0000); // 50 is zoom value
}
