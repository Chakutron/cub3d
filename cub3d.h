/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:57 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/19 17:19:01 by ocassany         ###   ########.fr       */
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
# define NC "\e[0m"

# define WIDTH 900
# define HEIGHT 450

typedef struct	s_rc
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_rc;

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
}					t_color;

typedef struct s_info
{
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
	t_color	floor;
	t_image	F_image;
	t_color	cell;
	t_image	C_image;
	int		w;
	int		h;
	char	**matrix;
	t_info	info;
	int		complete_info;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	double	xx;
	double	yy;
	double	x_temp;
	double	y_temp;
	int		angle;
	double	radians;
	int		nbr;
}		t_player;

typedef	struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
}		t_keys;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*win_ptr2;
	t_map		map;
	t_player	player;
	t_image		canvas;
	t_rc		rc;
	int			fd;
	char		*line;
	int			endgame;
	t_keys		key;
}				t_data;

char	*ft_strcat2(char *s, char c);
int		ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup2(char *s);
char	*ft_strjoin3(char *s1, char *s2);

t_image	new_img(int w, int h, t_data *window);
t_image	new_file_img(char *path, t_data *window);
void	put_pixel_img(t_image *img, int x, int y, int color);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);
int		create_trgb(int t, int r, int g, int b);
void	ft_draw_vertical_line(t_data *data, int x, int color);

void	open_map(t_data *data);
void	init_variables(t_data *data);
int		check_extension(t_data *data);
void	print_error(t_data *data, int error);
void	free_variables(t_data *data);
void	load_map(t_data *data);
int		x_press(t_data *data);
int		check_map(t_data *data);
t_image	load_image(char *file, t_data *data);
void	load_images(t_data *data);
int		title_render(t_data *data);
int		title_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
void	check_movement_keys(t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		handle_mouse_click(int button, int x, int y, t_data *data);
void	update_player(t_data *data, int x, int y);
void	work_animations(t_data *data);
void	show_map(t_data *data);
char	*ft_itoa(int n);
void	show_interface(t_data *data);
void	enemy_move(t_data *data);
void	close_game(t_data *data);
void	unload_images(t_data *data);

#endif