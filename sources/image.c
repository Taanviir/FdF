/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:10:17 by tanas             #+#    #+#             */
/*   Updated: 2023/02/21 23:23:22 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img image, int x, int y, int color)
{
	if (! (x >= image.line_length || y >= image.line_length || y < 0 || x < 0))
		*(unsigned int *) (image.addr + (y * image.line_length + x * (image.bpp / 8))) = color;
}

t_img	make_image(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img = mlx_new_image(window.mlx, w, h);
	image.addr = mlx_get_data_addr(image.img, &image.bpp,
			&image.line_length, &image.endian);
	image.height = h;
	image.width = w;
	return (image);
}
