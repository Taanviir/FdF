/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:10:15 by tanas             #+#    #+#             */
/*   Updated: 2023/02/05 23:26:58 by tanas            ###   ########.fr       */
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

# if __APPLE__
#  define KEYCODE_ESC 53
# endif

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_win
{
	void	*mlx;
	void	*window;
	int		height;
	int		width;
}			t_win;

typedef struct s_img
{
	t_win	win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}				t_img;

typedef struct s_pixel
{
	int	x;
	int	y;
}			t_pixel;

typedef struct s_data
{
	int	dx;
	int	dy;
	int	decision;
	int	s1;
	int	s2;
}			t_data;

typedef struct s_map
{
	int	width;
	int	height;
	int	**z_values;
}			t_map;

int		check_file(char *file, int count);
t_win	make_window(int w, int h, char *title);
void	my_pixel_put(t_img data, int x, int y, int color);
void	draw_line(t_pixel p1, t_pixel p2, t_img image);
t_img	make_image(int w, int h, t_win window);
int		key_events(int key_input, t_win *fdf);
int		close_window(t_win *fdf);
void	draw(t_map map, t_img image, t_pixel origin);
t_map	get_map(char *file);
t_map	get_values(char *line, int index, t_map);

#endif