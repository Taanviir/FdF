/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:15 by tanas             #+#    #+#             */
/*   Updated: 2023/02/23 23:02:20 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
}			t_win;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_values;
	int	**colours;
}			t_map;

typedef struct s_camera
{
	double	alpha;
	double	beta;
	double	gamma;
	int		x_offset;
	int		y_offset;
	double	zoom;
	double	z_value;
}			t_camera;

typedef struct s_img
{
	t_win		win;
	t_map		map;
	t_camera	*camera;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}			t_img;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	colour;
}			t_coord;

typedef struct s_data
{
	int	dx;
	int	dy;
	int	decision;
	int	s1;
	int	s2;
}			t_data;

int		check_file(char *file, int count);
t_win	make_window(int w, int h, char *title);
void	my_pixel_put(t_img data, int x, int y, int color);
void	draw_line(t_coord p1, t_coord p2, t_img image);
t_img	make_image(int w, int h, t_win window);
int		key_events(int key_input, t_img *image);
int		close_window(t_win *fdf);
void	draw(t_img image);
t_map	get_map(char *file);
t_coord	new_point(int x, int y, t_map map);
void	controls(t_win fdf);
int		*extract_colours(char **values_in_line, t_map map);
void	project(t_coord *c, t_img image);

#endif