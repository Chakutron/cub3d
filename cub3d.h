/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:57 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/07 13:49:26 by mchiboub         ###   ########.fr       */
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
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
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
	t_color	cell;
	int		w;
	int		h;
	int		**matrix;
	t_info	info;
	int		complete_info;
}			t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	angle;
}		t_player;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_player	player;
}				t_data;

char	*ft_strcat2(char *s, char c);
int		ft_atoi(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup2(char *s);

t_image	new_img(int w, int h, t_data *window);
t_image	new_file_img(char *path, t_data *window);
void	put_pixel_img(t_image *img, int x, int y, int color);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);

void	open_map(t_data *data);
void	init_variables(t_data *data);
int		check_extension(t_data *data);
void	print_error(t_data *data, int error);
void	load_map(t_data *data);
int		check_map(t_data *data);
t_image	load_image(char *file, t_data *data);
void	load_images(t_data *data);
int		title_render(t_data *data);
int		title_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
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
