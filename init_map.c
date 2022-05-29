/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:04:16 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/27 03:29:31 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ig_draw(t_gen *gen, void *img, int x, int y)
{
	mlx_put_image_to_window(gen->mlx, gen->win, img, x * 64, y * 64);
}

void	ig_draw_c(t_gen *gen, int j, int i)
{
	ig_draw(gen, gen->items, j, i);
	gen->currscore++;
}

void	ig_draw_p(t_gen *gen, int j, int i)
{
	ig_draw(gen, gen->play, j, i);
	gen->width = j;
	gen->height = i;
}

void	init_map(t_gen *gen)
{
	int	i;
	int	j;

	i = 0;
	while (gen->mapdata[i])
	{
		j = 0;
		while (gen->mapdata[i][j])
		{
			if (gen->mapdata[i][j] == '1')
				ig_draw(gen, gen->wall, j, i);
			else if (gen->mapdata[i][j] == '0')
				ig_draw(gen, gen->emspace, j, i);
			else if (gen->mapdata[i][j] == 'C')
				ig_draw_c(gen->items, j, i);
			else if (gen->mapdata[i][j] == 'E')
				ig_draw(gen, gen->exit, j, i);
			else if (gen->mapdata[i][j] == 'P')
				ig_draw_p(gen->play, j, i);
			else if (gen->mapdata[i][j] == 'F')
				ig_draw(gen, gen->enemy, j, i);
			j++;
		}
		i++;
	}
}
