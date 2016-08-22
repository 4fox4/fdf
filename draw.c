/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:55:03 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/15 15:43:37 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_point_x(t_env *e)
{
	e->x1 = e->x * e->esp;
	e->y1 = e->y * e->esp;
	e->x2 = (e->x - 1) * e->esp;
	e->y2 = e->y * e->esp;
}

void		ft_point_y(t_env *e)
{
	e->x1 = e->x * e->esp;
	e->y1 = e->y * e->esp;
	e->x2 = e->x * e->esp;
	e->y2 = (e->y - 1) * e->esp;
}

void		draw(t_env *e)
{
	e->y = 0;
	while (e->y < e->y_max)
	{
		e->x = 0;
		while (e->x < e->x_max)
		{
			if (e->x > 0)
			{
				ft_point_x(e);
				iso_converter_x(e);
			}
			if (e->y > 0)
			{
				ft_point_y(e);
				iso_converter_y(e);
			}
			e->x++;
		}
		e->y++;
	}
}

void		put_image(t_env *e, int x, int y)
{
	e->r = 0xFF;
	e->g = 0x66;
	e->b = 0xFF;

	if (x < 0 || x > HEIGHT || y < 0 || y > WIDTH)
		return ;
	*(e->data + x * e->size_line + e->bpp / 8 * y) = e->b;
	*(e->data + x * e->size_line + e->bpp / 8 * y + 1) = e->g;
	*(e->data + x * e->size_line + e->bpp / 8 * y + 2) = e->r;
}

void		draw_l(t_env *e)
{
	e->dx = fabs(e->s_x2 - e->s_x1);
	e->sx = e->s_x1 < e->s_x2 ? 1 : -1;
	e->dy = fabs(e->s_y2 - e->s_y1);
	e->sy = e->s_y1 < e->s_y2 ? 1 : -1;
	e->err = (e->dx > e->dy ? e->dx : -e->dy) / 2;
	while (e->s_x1 != e->s_x2 || e->s_y1 != e->s_y2)
	{
		// mlx_pixel_put(e->mlx, e->window, (int)e->s_x1 + e->t_x, \
		// 						(int)e->s_y1 + e->t_y, e->color);
		put_image(e, (int)e->s_y1 + e->t_y, (int)e->s_x1 + e->t_x);
		e->e2 = e->err;
		if (e->e2 > -e->dx)
		{
			e->err -= e->dy;
			e->s_x1 += e->sx;
		}
		if (e->e2 < e->dy)
		{
			e->err += e->dx;
			e->s_y1 += e->sy;
		}
	}
}
