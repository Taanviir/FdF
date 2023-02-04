/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:54:45 by tanas             #+#    #+#             */
/*   Updated: 2023/02/04 22:59:47 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_file(char *file, int count)
{
	int		fd;

	if (count != 2)
	{
		ft_putendl_fd(".fdf file is missing.", 2);
		ft_putendl_fd("Use \"./fdf [map].fdf\" to run this program.", 2);
		exit (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 3)
	{
		close(fd);
		ft_putendl_fd("Error. Invalid file entered.", 2);
		ft_putendl_fd("Use \"./fdf [map].fdf\" to run this program.", 2);
		exit (0);
	}
	close(fd);
	return (1);
}
