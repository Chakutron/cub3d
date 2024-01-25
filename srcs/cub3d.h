/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:57 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 18:36:40 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "gnl/get_next_line.h"
# include <stdnoreturn.h>
# include <math.h>

# define BLACK "\e[30m"
# define BLACKB "\e[40m"
# define RED "\e[31m"
# define REDB "\e[41m"
# define GREEN "\e[32m"
# define GREENB "\e[42m"
# define YELLOW "\e[33m"
# define YELLOWB "\e[43m"
# define BLUE "\e[34m"
# define BLUEB "\e[44m"
# define VIOLET "\e[35m"
# define VIOLETB "\e[45m"
# define GRAY "\e[90m"
# define GRAYB "\e[100m"
# define NC "\e[0m"

# define HEIGHT 450
# define WIDTH 900
# define MINIMAP 450
# define RATIO 5
# define RAYS 128

typedef struct s_dm
{
	int	y_offset;
	int	x_offset;
}		t_dm;

typedef struct s_ds
{
	int	y_init;
	int	x_init;
	int	extra;
	int	color;	
}		t_ds;

typedef struct s_rc
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
}			t_rc;

typedef struct	s_r3d
{
	float	y_init;
	float	x_init;
	float	y_end;
	float	x_end;
	char	wall;
	int		texture_init;
}			t_r3d;

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}		t_color;

typedef struct s_info
{
	int	i;
	int	n;
	int	s;
	int	w;
	int	e;
	int	f;
	int	c;
}		t_info;

typedef struct s_map
{
	char	*filename;
	char	*NO_file;
	t_image	NO_texture;
	char	*SO_file;
	t_image	SO_texture;
	char	*WE_file;
	t_image	WE_texture;
	char	*EA_file;
	t_image	EA_texture;
	t_image	D_texture;
	t_color	floor;
	t_image	F_image;
	t_color	cell;
	t_image	C_image;
	int		w;
	int		h;
	char	**matrix;
	t_info	info;
	int		complete_info;
	int		mapstart;	
	int		error_found;
	int		i;
}			t_map;

typedef struct s_walk
{
	t_image texture[21];
	int		index;
}			t_walk;

typedef struct s_player
{
	int		x;
	int		y;
	double	xx;
	double	yy;
	double	x_old;
	double	y_old;
	double	x_temp;
	double	y_temp;
	float	angle;
	float	radians;
	int		nbr;
	float	speed;
	t_walk	walk;
	int		walk_offset;
}		t_player;

typedef	struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
}		t_keys;

typedef struct s_tmp
{
	int	y;
	int x;
	int yy;
	int xx;
	int	y0;
	int	x0;
	int	y1;
	int	x1;
	int	dx;
	int	dy;
	int sx;
	int sy;
	int err;
	int e2;
}		t_tmp;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
	t_image		canvas;
	t_rc		rc;
	t_r3d		r3d[RAYS + 1];
	t_ds		ds;
	t_dm		dm;
	int			fd;
	int			fd2;
	char		*line;
	int			endgame;
	t_keys		key;
	int			i;
	float		rc_dist_offset;
	int			ratio;
	int			cursor_x;
	float		timer;
	t_tmp		tmp;
}				t_data;

void	add_spaces2map(t_data *data);
void	add_spaces2map_2(t_data *data, int y, char **minimap);
void	calculate_vector_player(t_data *data);
void	ceiling_variable(t_data *data, char *line, char *tmp, int nbr);
int		check_extension(t_data *data);
int		check_map(t_data *data);
void	check_movement_keys(t_data *data);
int		check_nearly_elems(t_data *data, int x, int y);
int		check_surround(t_data *data, int x, int y);
void	check_variables(t_data *data);
void	clean_return_line(char *str);
void	close_game(t_data *data);
int		create_trgb(int t, int r, int g, int b);
void	draw_background(t_data *data);
void	draw_door(t_data *data, int index);
void	draw_line(t_data *data);
void	draw_minimap(t_data *data);
void	draw_player(t_data *data);
void	draw_rays(t_data *data);
void	draw_square(t_data *data);
void	draw_walk(t_data *data);
void	draw_wall(t_data *data, int index);
void	east(int x, int y, t_data *data);
void	east_wall(t_data *data, int index, int y, int x);
void	empty_space(int x, int y, t_data *data);
void	finish_gnl(t_data *data);
void	floor_variable(t_data *data, char *line, char *tmp, int nbr);
void	free_elements_store_map(t_data *data);
void	free_variables(t_data *data);
uint	get_pixel_img(t_image *img, int x, int y);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
void	identifiers(int x, int y, t_data *data);
void	init_variables(t_data *data);
t_image	load_image(char *file, t_data *data);
void	load_images(t_data *data);
void	load_map(t_data *data);
void	make_floor_and_cell(t_data *data);
t_image	new_file_img(char *path, t_data *window);
t_image	new_img(int w, int h, t_data *window);
void	north(int x, int y, t_data *data);
void	north_wall(t_data *data, int index, int y, int x);
void	open_map(t_data *data);
void	print_error(t_data *data, int error);
void	print_variables(t_data *data);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);
void	put_pixel_img(t_image *img, int x, int y, int color);
void	read_line_by_line(t_data *data);
void	read_variables(t_data *data, char *line);
int		render(t_data *data);
void	south(int x, int y, t_data *data);
void	south_wall(t_data *data, int index, int y, int x);
void	start_game(t_data *data);
void	undo_movement(t_data *data);
void	unload_images(t_data *data);
void	update_player(t_data *data, int x, int y);
void	update(t_data *data);
void	west(int x, int y, t_data *data);
void	west_wall(t_data *data, int index, int y, int x);
void	write_error(char *str);
int		x_press(t_data *data);

int		check_size(long int n);
int			ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
char		*ft_strcat2(char *s, char c);
char		*ft_strdup2(char *s);
char		*ft_strjoin3(char *s1, char *s2);
void	worker(char *str, int size, long int num);

#endif
