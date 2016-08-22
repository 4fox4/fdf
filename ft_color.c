/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:05:48 by houlekhi          #+#    #+#             */
/*   Updated: 2015/04/21 10:56:17 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_color(int keycode, t_env *e)
{
	DB("koikoi");
	if (keycode == 15)
		e->color = 0xff0000;
	if (keycode == 'g')
		e->color = 0x00ff00;
	if (keycode == 'b')
		e->color = 0x0000ff;
	if (keycode == 's')
		e->color = 0x82d4fd;
	if (keycode == 'p')
		e->color = 0xffa5ee;
	if (keycode == 'w')
		e->color = 0xffffff;
	if (keycode == 'z')
		e->color = 0x000000;
	if (keycode == 'f')
		e->color = 0x62ff54;
	if (keycode == 'y')
		e->color = 0xf0ff00;
	if (keycode == 'o')
		e->color = 0xff972d;
}
