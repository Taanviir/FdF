/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:49:01 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 23:02:07 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_coord(int y, int *x, int z, double alpha, double beta, double gamma)
{
	int	x_old;

	x_old = *x;
	*x = (x_old * cos(beta) * cos(gamma)) + \
		(y * sin(alpha) * sin(beta) * cos(gamma)) - \
		(y * cos(alpha) * sin(gamma)) + \
		(z * cos(alpha) * sin(beta) * cos(gamma)) + \
		(z * sin(alpha) * sin(gamma));
}

void	rotate_y_coord(int *y, int x, int z, double alpha, double beta, double gamma)
{
	int	y_old;

	y_old = *y;
	*y = (x * cos(beta) * sin(gamma)) + \
		(y_old * sin(alpha) * sin(beta) * sin(gamma)) + \
		(y_old * cos(alpha) * cos(gamma)) + \
		(z * cos(alpha) * sin(beta) * sin(gamma)) - \
		(z * sin(alpha) * cos(gamma));
}

void	project(t_coord *c, t_img image)
{
	rotate_x_coord(c->y, &c->x, c->z, \
		image.camera->alpha, image.camera->beta, image.camera->gamma);
	rotate_y_coord(&c->y, c->x, c->z, \
		image.camera->alpha, image.camera->beta, image.camera->gamma);
}
