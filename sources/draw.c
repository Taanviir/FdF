/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 23:01:24 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	new_coord(int x, int y, t_map map)
{
	t_coord	new_coord;

	new_coord.x = x;
	new_coord.y = y;
	new_coord.z = map.z_values[y][x];
	return (new_coord);
}

void	draw(t_img image)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < image.map.height)
	{
		coord.x = 0;
		while (coord.x < image.map.width)
		{
			if (coord.x < (image.map.width - 1))
				draw_line(new_coord(coord.x, coord.y, image.map), \
					new_coord(coord.x + 1, coord.y, image.map), image);
			if (coord.y < (image.map.height - 1))
				draw_line(new_coord(coord.x, coord.y, image.map), \
					new_coord(coord.x, coord.y + 1, image.map), image);
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(image.win.mlx, image.win.window, image.img, 0, 0);
}
