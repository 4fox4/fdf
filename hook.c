/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:32:49 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 15:55:49 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_zoom(int keycode, t_env *e)
{
	if (keycode == KEY_PLUS)
	{
		e->cst += 1;
		e->zv += 1;
	}
	if (keycode == KEY_MINUS)
		if (e->cst > 1)
		{
			e->cst -= 1;
			if (e->zv > 1)
				e->zv -= 1;
		}
}

void		key_z_var(int keycode, t_env *e)
{
	if (keycode == KEY_NUM_1)
		e->zv += 1;
	if (keycode == KEY_NUM_0)
		if (e->zv > 1)
			e->zv -= 1;
}

int			key_hook(int keycode, t_env *e)
{
	printf("keycode : [%d]\n", keycode);
	if ((keycode >= KEY_LEFT && keycode <= KEY_UP) \
		|| (keycode >= KEY_MULT && keycode <= KEY_NUM_9))
	{
		mlx_destroy_image(e->mlx, e->img);
		e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	}
	key_zoom(keycode, e);
	key_z_var(keycode, e);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_UP)
		e->t_y -= 5;
	if (keycode == KEY_DOWN)
		e->t_y += 5;
	if (keycode == KEY_RIGHT)
		e->t_x += 5;
	if (keycode == KEY_LEFT)
		e->t_x -= 5;
	if (keycode >= 1 && keycode <= 35)
		ft_color(keycode, e);
	draw(e);
	put_img_to_win(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	return (0);
}
