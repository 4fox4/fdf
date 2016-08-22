/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 12:30:27 by houlekhi          #+#    #+#             */
/*   Updated: 2015/02/12 14:54:50 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error(int err)
{
	if (err == 1)
		ft_putendl("Enter 1 map with '.fdf' extension");
	if (err == 2)
		ft_putendl("Enable to load mlx");
	if (err == 3)
		ft_putendl("File must have .fdf extension");
	if (err == 4)
		ft_putendl("File doesn't exist");
	exit(0);
}
