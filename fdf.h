/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:29:26 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/08 11:44:32 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 2500
# define HEIGHT 1300

# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_MULT 67
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DIV 75
# define KEY_NUM_0 82
# define KEY_NUM_1 83
# define KEY_NUM_2 84
# define KEY_NUM_3 85
# define KEY_NUM_4 86
# define KEY_NUM_5 87
# define KEY_NUM_6 88
# define KEY_NUM_7 89
# define KEY_NUM_8 91
# define KEY_NUM_9 92

# define DB(x) ft_putendl(x)

typedef struct		s_env
{
	void			*mlx;
	void			*window;
	int				**tab;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				x_max;
	int				y_max;
	int				y;
	int				x;
	double			z;
	int				esp;
	int				color;
	int				color_res;
	double			zv;
	double			cst;
	int				t_x;
	int				t_y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			s_x1;
	double			s_y1;
	double			s_x2;
	double			s_y2;
	int				i;
	double			dx;
	double			sx;
	double			dy;
	double			sy;
	double			err;
	double			e2;

	int				r;
	int				g;
	int				b;
}					t_env;

int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					expose_hook(t_env *e);
void				draw(t_env *e);
void				draw_l(t_env *e);
int					**get_first_level(char *str, t_env *e);
void				iso_converter_x(t_env *e);
void				iso_converter_y(t_env *e);
void				ft_init(t_env *e);
int					error(int err);
void				ft_color(int keycode, t_env *e);
int					put_img_to_win(t_env *e);

#endif
