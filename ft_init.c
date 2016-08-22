/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:13:56 by houlekhi          #+#    #+#             */
/*   Updated: 2015/04/29 14:57:51 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_env *e)
{
	e->x_max = -1;
	e->esp = 16;
	e->zv = 1;
	e->color = 0x00c5ff;
	e->cst = 0.5;
	e->t_x = 400;
	e->t_y = 300;
	e->i = 0;
}
