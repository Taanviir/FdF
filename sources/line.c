/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:02:57 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 23:04:50 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

static int	ft_swap(t_data *data)
{
	int	tmp;

	if (data->dx < data->dy)
	{
		tmp = data->dx;
		data->dx = data->dy;
		data->dy = tmp;
		return (1);
	}
	return (0);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	draw_line(t_coord c1, t_coord c2, t_img image)
{
	int		i;
	int		swap;
	t_data	data;

	// ZOOM //
	c1.x *= image.camera->zoom;
	c1.y *= image.camera->zoom;
	c1.z *= image.camera->zoom / image.camera->z_value;
	c2.x *= image.camera->zoom;
	c2.y *= image.camera->zoom;
	c2.z *= image.camera->zoom / image.camera->z_value;
	
	// CENTERING THE ROTATION
	c1.x -= (image.map.width * image.camera->zoom / 2);
	c1.y -= (image.map.height * image.camera->zoom / 2);
	c2.x -= (image.map.width * image.camera->zoom / 2);
	c2.y -= (image.map.height * image.camera->zoom / 2);

	// ROTATION
	c1.x = (c1.x * cos(image.camera->beta) * cos(image.camera->gamma)) + \
		((c1.y * sin(image.camera->alpha) * sin(image.camera->beta) * cos(image.camera->gamma)) - (c1.y * cos(image.camera->alpha) * sin(image.camera->gamma))) \
			+ ((c1.z * cos(image.camera->alpha) * sin(image.camera->beta) * cos(image.camera->gamma)) + (c1.z * sin(image.camera->alpha) * sin(image.camera->gamma)));
	c1.y = (c1.x * cos(image.camera->beta) * sin(image.camera->gamma)) + ((c1.y * sin(image.camera->alpha) * sin(image.camera->beta) * sin(image.camera->gamma)) + (c1.y * cos(image.camera->alpha) * cos(image.camera->gamma))) \
		+ ((c1.z * cos(image.camera->alpha) * sin(image.camera->beta) * sin(image.camera->gamma)) - (c1.z * sin(image.camera->alpha) * cos(image.camera->gamma)));

	c2.x = (c2.x * cos(image.camera->beta) * cos(image.camera->gamma)) + \
		((c2.y * sin(image.camera->alpha) * sin(image.camera->beta) * cos(image.camera->gamma)) - (c2.y * cos(image.camera->alpha) * sin(image.camera->gamma))) \
			+ ((c2.z * cos(image.camera->alpha) * sin(image.camera->beta) * cos(image.camera->gamma)) + (c2.z * sin(image.camera->alpha) *sin(image.camera->gamma)));
	c2.y = (c2.x * cos(image.camera->beta) * sin(image.camera->gamma)) + ((c2.y * sin(image.camera->alpha) * sin(image.camera->beta) * sin(image.camera->gamma)) + (c2.y * cos(image.camera->alpha) * cos(image.camera->gamma))) \
		+ ((c2.z * cos(image.camera->alpha) * sin(image.camera->beta) * sin(image.camera->gamma)) - (c2.z * sin(image.camera->alpha) * cos(image.camera->gamma)));

	// OFFSET
	c1.x += ((WIDTH + image.camera->x_offset) / 2);
	c1.y += ((HEIGHT + image.camera->y_offset) / 2);
	c2.x += ((WIDTH + image.camera->x_offset) / 2);
	c2.y += ((HEIGHT + image.camera->y_offset) / 2);

	data.dx = ft_abs(c2.x - c1.x);
	data.dy = ft_abs(c2.y - c1.y);
	data.s1 = get_sign(c2.x - c1.x);
	data.s2 = get_sign(c2.y - c1.y);
	swap = ft_swap(&data);
	data.decision = 2 * data.dy - data.dx;
	i = 0;
	while (i <= data.dx)
	{
		my_pixel_put(image, c1.x, c1.y, 0xFFFFFF);
		while (data.decision > 0)
		{
			data.decision -= (2 * data.dx);
			c1.x += (data.s1 * swap);
			c1.y += (data.s2 * !swap);
		}
		data.decision += (2 * data.dy);
		c1.y += (data.s2 * swap);
		c1.x += (data.s1 * !swap);
		i++;
	}
}
