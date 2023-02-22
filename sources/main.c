/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:12 by tanas             #+#    #+#             */
/*   Updated: 2023/02/22 14:31:06 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_win		fdf;
	t_img		image;
	t_camera	camera;

	if (check_file(argv[1], argc))
	{
		fdf = make_window(WIDTH, HEIGHT, "FdF");
		if (!fdf.mlx || !fdf.window)
			return (1);
		image = make_image(WIDTH, HEIGHT, fdf);
		image.map = get_map(argv[1]);
		camera.zoom = 1;
		camera.z_value = 5;
		camera.x_offset = 0;
		camera.y_offset = 0;
		image.camera = &camera;
		draw(image);
		mlx_hook(fdf.window, 2, 1L << 0, key_events, &image);
		mlx_hook(fdf.window, 17, 1L << 17, close_window, &image);
		mlx_loop(fdf.mlx);
	}
}
