/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:29:38 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/30 02:02:52 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	read_map(char *arg, t_gen *gen)
{
	int		fd;
	int		lines;
	char	*all;

	all = NULL;
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		errors(3);
	gen->mapdata = (char **)malloc(sizeof(char *) * (ft_strlen(fd)));
	while (fd)
	{
		lines = read(fd, gen->mapdata, 10);
	}
	gen->mapdata[lines] = '\0';
	close(fd);
}

static void	*img_init(char *img, t_gen *gen)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(gen->mlx, img,
			&gen->img_size.x, &gen->img_size.y);
	return (img_ptr);
}

void	init_game(t_gen *gen)
{
	gen->width = ft_strlen(gen->mapdata[0]);
	gen->height = mapheight(gen->mapdata);
	gen->win_size.x = gen->width * 64;
	gen->win_size.y = gen->height * 64;
	gen->mlx = mlx_init();
	gen->win = mlx_new_window(gen->mlx, gen->win_size.x,
			gen->win_size.y, "so_long");
	gen->currscore = 0;
	gen->steps = 0;
	mlx_hook(gen->win, 17, 0, game_over, gen);
	gen->wall = img_init(IMG_W, gen);
	gen->play = img_init(IMG_P, gen);
	gen->items = img_init(IMG_C, gen);
	gen->emspace = img_init(IMG_S, gen);
	gen->exit = img_init(IMG_E, gen);
	gen->enemy = img_init(IMG_EN, gen);
}

// static void	right_name(char *name)
// {
// 	int		i;
// 	t_gen	gen;

// 	i = 0;
// 	if (name[i])
// 	{
// 		if (name[i] == '.')
// 		{
// 			if (ft_strncmp(&name[i], ".ber", 5))
// 				read_map(name, &gen);
// 		}
// 		i++;
// 	}
// 	printf("%s", "OK");
// 	errors(2);
// }

void	check_format(char *arg)
{
	char	*ber;
	t_gen	gen;

	ber = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (ber == NULL)
		errors(2);
	if (ber)
	{
		read_map(arg, &gen);
		// check_map(&gen);
		// init_game(&gen);
		// init_map(&gen);
		// game_hook(&gen);
		// mlx_loop(gen.mlx);
	}
}
