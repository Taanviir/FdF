/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:12 by tanas             #+#    #+#             */
/*   Updated: 2023/02/06 18:57:25 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_win	fdf;
	t_img	image;
	t_pixel	origin;
	t_map	map;

	if (check_file(argv[1], argc))
	{
		fdf = make_window(WIDTH, HEIGHT, "FdF");
		if (!fdf.mlx || !fdf.window)
			return (1);
		image = make_image(1000, 1000, fdf);
		origin.x = 20;
		origin.y = 20;
		map = get_map(argv[1]);
		draw(map, image, origin);
		mlx_put_image_to_window(fdf.mlx, fdf.window, image.img, 0, 0);
		mlx_hook(fdf.window, 2, 1L << 0, key_events, &fdf);
		mlx_hook(fdf.window, 17, 1L << 17, close_window, &fdf);
		mlx_loop(fdf.mlx);
	}
}
