/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:54:45 by tanas             #+#    #+#             */
/*   Updated: 2023/02/05 17:56:46 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* need to make a common error function that takes care of any error
void	error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
}

=========== ERRNO =============
0	Default
1	Operation not permitted
2	No such file or directory
3	No such process
4	Interrupted system call
5	I/O error
6	No such device or address
7	Argument list too long
8	Exec format error
9	Bad file number
10	No child processes
11	Try again
12	Out of memory
13	Permission denied

*/

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
