/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:07:35 by tanas             #+#    #+#             */
/*   Updated: 2023/02/04 19:07:43 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(int w, int h, t_img image, t_pixel origin)
{
	t_pixel	pixel;

	pixel.y = 20;
	pixel.x = 20;
	while (pixel.y < (h + 400))
	{
		pixel.x = 20;
		origin.x = pixel.x;
		while (pixel.x < (w + 400))
		{
			draw_line(origin, pixel, image);
			origin = pixel;
			pixel.x += 20;
		}
		pixel.y += 20;
	}
}
