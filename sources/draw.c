/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/13 21:29:54 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map map, t_img image, t_pixel origin)
{
	t_pixel	pixel;

	pixel.y = 0;
	pixel.x = 0;
	while (pixel.y < map.height)
	{
		pixel.x = 0;
		origin = pixel;
		while (pixel.x < map.width)
		{
			if (pixel.x < (map.width - 1))
				draw_line(origin, pixel.x + 1, pixel.y, image);
			if (pixel.y < (map.height - 1))
				draw_line(origin, pixel.x, pixel.y + 1, image);
			pixel.x++;
			origin = pixel;
		}
		pixel.y++;
	}
	if ((pixel.y == map.height) && (pixel.x == map.width))
		my_pixel_put(image, (pixel.x - 1) * 50, (pixel.y - 1) * 50, 0x00FF0000); // 50 is zoom value
}
