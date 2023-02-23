/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:57 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 22:35:59 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycodes.h"

int	close_window(t_win *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
}

void	move(int key_input, t_img image)
{
	ft_memset(image.addr, 0, (HEIGHT * WIDTH * 4));
	if (key_input == ARROW_UP)
		image.camera->y_offset -= 10;
	else if (key_input == ARROW_DOWN)
		image.camera->y_offset += 10;
	else if (key_input == ARROW_LEFT)
		image.camera->x_offset -= 10;
	else if (key_input == ARROW_RIGHT)
		image.camera->x_offset += 10;
	draw(image);
}

void	rotate(int key_input, t_img image)
{
	ft_memset(image.addr, 0, (HEIGHT * WIDTH * 4));
	if (key_input == KEY_A)
		image.camera->alpha += (1 * (M_PI / 180));
	else if (key_input == KEY_D)
		image.camera->alpha -= (1 * (M_PI / 180));
	else if (key_input == KEY_Q)
		image.camera->beta += (1 * (M_PI / 180));
	else if (key_input == KEY_E)
		image.camera->beta -= (1 * (M_PI / 180));
	else if (key_input == KEY_W)
		image.camera->gamma += (1 * (M_PI / 180));
	else if (key_input == KEY_S)
		image.camera->gamma -= (1 * (M_PI / 180));
	else if (key_input == KEY_T)
	{
		image.camera->alpha = 0;
		image.camera->beta = 0;
		image.camera->gamma = 0;
	}
	else if (key_input == KEY_I)
	{
		image.camera->alpha = (0 * (M_PI / 180));
		image.camera->beta = (0 * (M_PI / 180));
		image.camera->gamma = (0 * (M_PI / 180));
	}
	printf("alpha: %f\nbeta: %f\ngamma: %f\n\n", image.camera->alpha, image.camera->beta, image.camera->gamma);
	draw(image);
}

void	zoom(int key_input, t_img image)
{
	ft_memset(image.addr, 0, (HEIGHT * WIDTH * 4));
	if (key_input == NUMPAD_PLUS)
		image.camera->zoom += 1;
	else if (key_input == NUMPAD_MINUS)
		image.camera->zoom -= 1;
	else if (key_input == MORE)
		image.camera->z_value += 0.1;
	else if (key_input == LESS)
		image.camera->z_value -= 0.1;
	if (image.camera->z_value < 0.1)
		image.camera->z_value = 0.1;
	if (image.camera->z_value > 10)
		image.camera->z_value = 10;
	printf("z_value: %f\n", image.camera->z_value);
	draw(image);
}

int	key_events(int key_input, t_img *image)
{
	if (key_input == ESCAPE)
		close_window(&image->win);
	else if (key_input == KEY_A || \
		key_input == KEY_W || \
		key_input == KEY_S || \
		key_input == KEY_Q || \
		key_input == KEY_E || \
		key_input == KEY_D || \
		key_input == KEY_T || \
		key_input == KEY_I)
		rotate(key_input, *image);
	else if (key_input == NUMPAD_MINUS || key_input == NUMPAD_PLUS || key_input == MORE || key_input == LESS)
		zoom(key_input, *image);
	else if (key_input == ARROW_DOWN || key_input == ARROW_LEFT || key_input == ARROW_UP || key_input == ARROW_RIGHT)
		move(key_input, *image);
	
	return (0);
}
