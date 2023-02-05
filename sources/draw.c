/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/05 21:28:10 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_map map, t_img image, t_pixel origin)
{
	t_pixel	pixel;

	pixel.y = 20;
	pixel.x = 20;
	while (pixel.y < (map.height + 400))
	{
		pixel.x = 20;
		origin.x = pixel.x;
		while (pixel.x < (map.width + 400))
		{
			draw_line(origin, pixel, image);
			origin = pixel;
			pixel.x += 20;
		}
		pixel.y += 20;
	}
}
