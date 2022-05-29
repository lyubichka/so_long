/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:34:22 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/24 17:45:21 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_rectangle(char **mapdata)
{
	int	i;

	i = 1;
	while (1)
	{
		if (ft_strlen(mapdata[i]) != ft_strlen(mapdata[i - 1]))
		{
			freemap(mapdata);
			errors(4);
		}
		i++;
	}
}

void	ft_wallsaround(char **mapdata)
{
	int		x;
	int		y;
	int		s_wid;
	int		s_hei;

	x = 0;
	y = 0;
	s_wid = ft_strlen(mapdata[x]);
	s_hei = mapheight(mapdata);
	while (x < s_wid)
	{
		if (mapdata[0][x] != '1' || mapdata[s_hei - 1][x] != '1')
			errors(5);
		x++;
	}
	while (y < s_wid)
	{
		if (mapdata[y][0] != '1' || mapdata[y][s_wid - 1] != '1')
			errors(5);
		y++;
	}
}

void	ft_symbols(char **mapdata)
{
	int	x;
	int	y;

	y = 0;
	while (mapdata[y])
	{
		x = 0;
		while (mapdata[y][x])
		{
			if (mapdata[y][x] != '1' && mapdata[y][x] != '0'
				&& mapdata[y][x] != 'C' && mapdata[y][x] != 'E'
				&& mapdata[y][x] != 'P')
				errors(6);
			x++;
		}
		y++;
	}
}

void	ft_countchars(t_gen *gen)
{
	int	x;
	int	y;

	gen->ppos = 0;
	gen->score = 0;
	gen->escape = 0;
	y = -1;
	while (gen->mapdata[++y])
	{
		x = -1;
		while (gen->mapdata[y][++x])
		{
			if (gen->mapdata[y][x] == 'P')
				gen->ppos++;
			if (gen->mapdata[y][x] == 'C')
				gen->score++;
			if (gen->mapdata[y][x] == 'E')
				gen->escape++;
		}
	}
	if (gen->ppos != 1 || gen->escape != 1)
		errors(7);
	if (gen->score == 0)
		errors(8);
}

void	check_map(t_gen *gen)
{
	ft_rectangle(gen->mapdata);
	ft_wallsaround(gen->mapdata);
	ft_symbols(gen->mapdata);
	ft_countchars(gen);
}
