/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:57 by tanas             #+#    #+#             */
/*   Updated: 2023/01/25 17:54:52 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_win *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->window);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
}

int	key_events(int key_input, t_win *fdf)
{
	if (key_input == KEYCODE_ESC)
		close_window(fdf);
	return (0);
}
