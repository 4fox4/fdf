/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:59:22 by houlekhi          #+#    #+#             */
/*   Updated: 2015/02/12 12:45:04 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				ft_nbline_infile(char const *str, t_env *e)
{
	int			i;
	int			fd;
	char		*line;

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0 || line[0] != '\0')
		i++;
	close(fd);
	e->y_max = i;
	return (i);
}

int				*fill_line(int *line, char **tmp, t_env *e)
{
	int			j;

	j = 0;
	while (tmp[j])
	{
		line[j] = ft_atoi(tmp[j]);
		j++;
	}
	if (e->x_max > -1)
		if (e->x_max != j)
		{
			ft_putendl("Empty Map");
			exit(0);
		}
	e->x_max = j;
	if (e->x_max <= 0)
	{
		ft_putendl("Map invalid");
		exit(0);
	}
	return (line);
}

int				**get_first_level(char *str, t_env *e)
{
	int			**map;
	char		*line;
	char		**tmp;
	int			fd;

	map = (int **)malloc(sizeof(int *) * ft_nbline_infile(str, e));
	if (!map)
		return (NULL);
	e->i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) || line[0] != '\0')
	{
		tmp = ft_strsplit(line, ' ');
		map[e->i] = (int *)malloc(sizeof(int) * ft_tablen(tmp));
		if (!(map[e->i]))
			return (NULL);
		map[e->i] = fill_line(map[e->i], tmp, e);
		free(line);
		free(tmp);
		e->i++;
	}
	free(line);
	close(fd);
	return (map);
}
