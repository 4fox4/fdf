/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 09:29:19 by houlekhi          #+#    #+#             */
/*   Updated: 2015/05/19 15:56:11 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->window, e->img, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	e;

	ft_init(&e);
	e.mlx = mlx_init();
	if (argc != 2)
		error(1);
	if (!e.mlx)
		error(2);
	if (ft_strstr(argv[1], ".fdf") == 0)
		error(3);
	e.window = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FdF");
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
    e.data = mlx_get_data_addr(e.img, &e.bpp, &e.size_line, &e.endian);
    e.tab = get_first_level(argv[1], &e);
	if (!e.tab)
		error(4);
	draw(&e);
	mlx_hook(e.window, 2, 3, key_hook, &e);
	mlx_mouse_hook(e.window, mouse_hook, &e);
    put_img_to_win(&e);
	mlx_expose_hook(e.window, put_img_to_win, &e);
	mlx_loop(e.mlx);
	return (0);
}
