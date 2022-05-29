/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:55:12 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/24 19:05:33 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_hook(t_gen *gen)
{
	mlx_hook(gen->win, 2, 1L << 0, &key_press, gen);
	mlx_hook(gen->win, 17, 0, &game_over, gen);
	mlx_hook(gen->win, 9, 1L << 21, &newmapdraw, gen);
}

int	key_press(int keycode, t_gen *gen)
{
	int	y;
	int	x;

	if (keycode == ESC)
		game_over(gen);
	else if (keycode == W)
		moving(gen, 'y', UP);
	else if (keycode == A)
		moving(gen, 'x', LEFT);
	else if (keycode == S)
		moving(gen, 'y', DOWN);
	else if (keycode == D)
		moving(gen, 'x', RIGHT);
	if (gen->mapdata[y][x] == 'E')
		you_win(gen);
	return (0);
}
