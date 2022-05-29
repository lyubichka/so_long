/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 04:39:12 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/23 17:03:27 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errors(int n)
{
	if (n == 1)
		printf("Error\nInvalid number of Arguments!");
	else if (n == 2)
		printf("Error\nInvalid map format!");
	else if (n == 3)
		printf("Error\nIncorrectly opened file!");
	else if (n == 4)
		printf("Error\nThe map is not rectangular!");
	else if (n == 5)
		printf("Error\nWalls are not around the perimeter!");
	else if (n == 6)
		printf("Error\nNot all characters are on the map!");
	else if (n == 7)
		printf("Error\nWrong number of characters!");
	else if (n == 8)
		printf("Error\nThere are no collectibles on the map!");
	exit(0);
}

void	freemap(char **mapdata)
{
	int	i;

	i = 0;
	while (mapdata[i])
		free(mapdata[i++]);
	free(mapdata);
	mapdata = NULL;
}

int	mapheight(char **mapdata)
{
	int	i;

	i = 0;
	while (mapdata[i])
		i++;
	return (i);
}

int	game_over(t_gen *gen)
{
	freemap(gen->mapdata);
	mlx_destroy_window(gen->mlx, gen->win);
	exit(0);
	return (0);
}
