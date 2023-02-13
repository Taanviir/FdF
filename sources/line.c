/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:02:57 by tanas             #+#    #+#             */
/*   Updated: 2023/02/13 21:34:24 by tanas            ###   ########.fr       */
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

void	draw_line(t_pixel p1, int x2, int y2, t_img image)
{
	int		i;
	int		swap;
	t_data	data;

	// zoom : 
	p1.x *= 50;
	p1.y *= 50;
	x2 *= 50;
	y2 *= 50;
	/////////////

	data.dx = ft_abs(x2 - p1.x);
	data.dy = ft_abs(y2 - p1.y);
	data.s1 = get_sign(x2 - p1.x);
	data.s2 = get_sign(y2 - p1.y);
	swap = ft_swap(&data);
	data.decision = 2 * data.dy - data.dx;
	i = 0;
	while (i < data.dx)
	{
		my_pixel_put(image, p1.x, p1.y, 0x00FF0000);
		while (data.decision >= 0)
		{
			data.decision -= (2 * data.dx);
			p1.x += (data.s1 * swap);
			p1.y += (data.s2 * !swap);
		}
		data.decision += (2 * data.dy);
		p1.y += (data.s2 * swap);
		p1.x += (data.s1 * !swap);
		i++;
	}
}
