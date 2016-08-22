/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 21:29:04 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/15 15:49:06 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso_converter_x(t_env *e)
{
	e->s_x1 = e->cst * e->x1 - e->cst * e->y1;
	e->s_y1 = -(((double)e->tab[e->y][e->x]) * e->zv) \
				+ (e->cst) / 2 * e->x1 + (e->cst) / 2 * e->y1;
	e->s_x2 = e->cst * e->x2 - e->cst * e->y2;
	e->s_y2 = -(((double)e->tab[e->y][e->x - 1]) * e->zv) \
				+ (e->cst) / 2 * e->x2 + (e->cst) / 2 * e->y2;
	draw_l(e);
}

void		iso_converter_y(t_env *e)
{
	e->s_x1 = e->cst * e->x1 - e->cst * e->y1;
	e->s_y1 = -(((double)e->tab[e->y][e->x]) * e->zv) \
				+ (e->cst) / 2 * e->x1 + (e->cst) / 2 * e->y1;
	e->s_x2 = e->cst * e->x2 - e->cst * e->y2;
	e->s_y2 = -(((double)e->tab[e->y - 1][e->x]) * e->zv) \
				+ (e->cst) / 2 * e->x2 + (e->cst) / 2 * e->y2;
	draw_l(e);
}
